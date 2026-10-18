# Software Security Engineering Lab

An applied software security and vulnerability research workspace exploring memory safety, exploit analysis, defensive systems engineering, and modern security mitigations, backed by an automated Terraform and Ansible cloud lab environment.

> **Context:** Graduate Research Project — **CMPE-279: Software Security Technologies** (Fall 2026)  
> **Researcher:** [John Ian Buñag](https://github.com/ianbunag)  
> **Infrastructure & Tooling:** [Terraform Cloud Lab](./terraform/) | [Ansible Automation](./ansible/)

## Prerequisites

### 1. Generate Deploy Key

Generate a dedicated ED25519 SSH key pair for the VM deploy key:

```bash
ssh-keygen -t ed25519 -C "cmpe-279.ianbunag.dev" -f ./id_ed25519_cmpe-279-ianbunag-dev
```

### 2. Add Deploy Key to GitHub Repository

Add the generated public key (`./id_ed25519_cmpe-279-ianbunag-dev.pub`) to the GitHub repository's deploy keys:

- Refer to the [GitHub Deploy Keys Documentation](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/managing-deploy-keys#set-up-deploy-keys).
- **Title**: Value of `deploy_key_secret_name` in [terraform/locals.tf](terraform/locals.tf)
- **Key**: Contents of `./id_ed25519_cmpe-279-ianbunag-dev.pub`

### 3. Create GCP Secret Manager Secret

Store the private key in Google Cloud Secret Manager:

- **Name**: Value of `deploy_key_secret_name` in [terraform/locals.tf](terraform/locals.tf)
- **Secret value**: Contents of `./id_ed25519_cmpe-279-ianbunag-dev` (the private key)
- **Replication policy**:
  - **Manually manage locations for this secret**: Enabled
  - **Location(s)**: `us-west1`

## Terraform Lab Provisioning

This repository's [`terraform/`](./terraform/) directory is designed as a reusable module to provision the security lab environment on Google Cloud Platform with Cloudflare DNS routing:

```hcl
provider "cloudflare" {
  api_token = ""
}

provider "google" {
  project               = ""
  region                = "us-west1"
  zone                  = "us-west1-b"
  user_project_override = true
}

module "software_security_engineering" {
  source                                  = "git@github.com:ianbunag/software-security-engineering.git//terraform"
  root_domain                             = ""
  cloudflare_update_dns_token_secret_name = ""
  cloudflare_zone_id                      = ""
  ssh_public_key_file                     = ""
  ssh_username                            = ""
}
```

## Remote Development

### CLion Deployment Configuration

You can configure CLion for remote development via SFTP file synchronization using JetBrains' built-in deployment tooling. For general reference, see the [CLion Deployment Settings Documentation](https://www.jetbrains.com/help/clion/settings-deployment.html).

1. In CLion, navigate to **Tools** > **Deployment** > **Configuration...**.
2. Click **+** to add a new server configuration.

#### Connection Settings

| Setting | Value |
| :--- | :--- |
| **Type** | `SFTP` |
| **Root path** | `/home/<username>/Documents/remote-cmpe-279-software-security-technologies` |
| **Use rsync for download/upload/sync** | Enabled |

#### Mappings

Switch to the **Mappings** tab:

| Setting | Value |
| :--- | :--- |
| **Local path** | `<project-root>` |
| **Deployment path** | `/` |
