resource "cloudflare_dns_record" "vm" {
  zone_id = var.cloudflare_zone_id
  name    = local.slug
  type    = "A"
  content = "192.0.2.1"
  ttl     = 1
  comment = local.git_repository
  lifecycle {
    ignore_changes = [content]
  }
}

resource "google_service_account" "vm" {
  account_id   = "${local.slug}-vm"
  display_name = "${upper(local.slug)} VM"
}

resource "google_secret_manager_secret_iam_member" "vm_secrets" {
  for_each = toset([
    var.cloudflare_update_dns_token_secret_name,
    local.deploy_key_secret_name
  ])
  secret_id = each.value
  role      = "roles/secretmanager.secretAccessor"
  member    = "serviceAccount:${google_service_account.vm.email}"
}

resource "google_compute_instance" "vm" {
  name                      = local.slug
  machine_type              = "e2-micro"
  deletion_protection       = true
  allow_stopping_for_update = true

  boot_disk {
    initialize_params {
      image = "ubuntu-os-cloud/ubuntu-1604-xenial-v20210928"
      type  = "pd-standard"
      size  = 10
    }
  }

  network_interface {
    network = "default"
    access_config {
      # Ephemeral public IP
    }
  }

  service_account {
    email  = google_service_account.vm.email
    scopes = ["cloud-platform"]
  }

  metadata = {
    ssh-keys                                = trimspace(file(pathexpand(var.ssh_public_key_file)))
    domain                                  = local.domain
    cloudflare_update_dns_token_secret_name = var.cloudflare_update_dns_token_secret_name
    git_repository                          = local.git_repository
    git_email                               = local.git_email
    git_name                                = local.git_name
    cloudflare_zone_id                      = var.cloudflare_zone_id
    cloudflare_record_id                    = cloudflare_dns_record.vm.id
  }

  metadata_startup_script = <<-EOF
    #!/bin/bash
    set -euo pipefail

    if ! command -v ansible >/dev/null 2>&1; then
      apt-add-repository -y ppa:ansible/ansible-2.9
      apt-get update
      apt-get install -y ansible
    fi

    USER_HOME=$(eval echo "~${var.ssh_username}")
    SSH_DIR="$USER_HOME/.ssh"
    KEY_PATH="$SSH_DIR/id_ed25519"

    if [ ! -d "$SSH_DIR" ]; then
      install -d -m 700 -o "${var.ssh_username}" -g "${var.ssh_username}" "$SSH_DIR"
    fi

    if [ ! -f "$KEY_PATH" ]; then
      sudo -u "${var.ssh_username}" -H gcloud secrets versions access latest --secret="${local.deploy_key_secret_name}" > "$KEY_PATH"
      chmod 600 "$KEY_PATH"
    fi

    # Pre-populate GitHub's host keys so non-interactive git/ssh commands don't block on authenticity prompts.
    if [ ! -f "$SSH_DIR/known_hosts" ] || ! grep -q "github.com" "$SSH_DIR/known_hosts"; then
      sudo -u "${var.ssh_username}" -H bash -c 'ssh-keyscan -t rsa,ecdsa,ed25519 github.com >> "'"$SSH_DIR"'/known_hosts"' 2>/dev/null
      chmod 644 "$SSH_DIR/known_hosts"
    fi

    sudo -u "${var.ssh_username}" -H \
      ANSIBLE_LOG_PATH=/tmp/ansible.log \
      ansible-pull -U "${local.git_repository}" ansible-playbook.yml
  EOF
}
