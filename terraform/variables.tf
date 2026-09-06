variable "root_domain" {
  type        = string
  description = "Root domain name"
}

variable "cloudflare_update_dns_token_secret_name" {
  type        = string
  description = "Cloudflare update DNS token name"
}
