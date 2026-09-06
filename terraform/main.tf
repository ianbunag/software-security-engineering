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
