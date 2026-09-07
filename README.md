# CMPE-279 Software Security Technologies

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
