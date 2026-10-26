locals {
  slug                   = "cmpe-279"
  domain                 = "${local.slug}.${var.root_domain}"
  jammy_slug             = "cmpe-279-jammy"
  jammy_domain           = "${local.jammy_slug}.${var.root_domain}"
  git_repository         = "git@github.com:ianbunag/software-security-engineering.git"
  git_email              = "cmpe-279@ianbunag.dev"
  git_name               = "CMPE-279 Lab VM"
  deploy_key_secret_name = "cmpe-279-ianbunag-dev-github-deploy-key"
  jammy_gui_secret_name  = "cmpe-279-jammy-gui-password"
}
