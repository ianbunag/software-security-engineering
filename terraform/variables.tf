variable "root_domain" {
  type        = string
  description = "Root domain name"
}

variable "cloudflare_update_dns_token_secret_name" {
  type        = string
  description = "Cloudflare update DNS token name"
}

variable "cloudflare_zone_id" {
  type        = string
  description = "Cloudflare zone ID"
}
