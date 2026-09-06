locals {
  slug           = "cmpe-279"
  domain         = "${local.slug}.${var.root_domain}"
  git_repository = "git@github.com:ianbunag/cmpe-279-software-security-technologies.git"
}
