# Cloudflare Tunnel (cloudflared) — Docker Quick Notes

Run a [Cloudflare Tunnel](https://developers.cloudflare.com/cloudflare-one/connections/connect-networks/) connector inside Docker. The connector makes an outbound-only connection to Cloudflare's edge, so you can expose services (web apps, SSH, internal APIs) to the Internet **without opening any inbound firewall ports** on the host or network.

This note covers the "remotely-managed tunnel" model: the tunnel is created and configured in the Cloudflare Zero Trust dashboard, and the connector only needs a token to run.

---

## Prerequisites

- Docker installed on the host (Linux or Windows with Docker Desktop / WSL2).
- A Cloudflare account with a domain (zone) added to Cloudflare.
- Admin access to the Cloudflare Zero Trust dashboard: <https://one.dash.cloudflare.com>

## Quick start

```sh
docker run -d --name cloudflared --restart unless-stopped cloudflare/cloudflared:latest tunnel --no-autoupdate run --token <YOUR_TOKEN>
```

Replace `<YOUR_TOKEN>` with the token shown in the Cloudflare dashboard (see below). The container starts, connects to the nearest Cloudflare data center, and begins serving the public hostnames configured for the tunnel.

### Where to get the token

1. Open **Cloudflare Zero Trust** → **Networks** → **Tunnels**.
2. Click **Create a tunnel**, choose **Cloudflared** as the connector type.
3. Give the tunnel a name and create it.
4. The dashboard shows a `docker run` command containing the token in `--token <YOUR_TOKEN>`. Copy that token value.
5. Under the **Public Hostnames** tab, map hostnames (e.g. `app.example.com`) to your internal services (e.g. `http://localhost:8080`).

The token is a long-lived credential — treat it like a password (see [Security](#security)).

## Command breakdown

| Part | Meaning |
| --- | --- |
| `docker run -d` | Run the container detached (in the background). |
| `--name cloudflared` | Give the container a fixed name so it is easy to manage. |
| `--restart unless-stopped` | Automatically restart the connector after crashes or host reboots. |
| `cloudflare/cloudflared:latest` | Official image from Docker Hub. Pin a version (`:2025.x.x`) in production for reproducibility. |
| `tunnel ... run` | Run a tunnel (as opposed to `cloudflared` CLI subcommands like `access`). |
| `--no-autoupdate` | Disable in-container auto-update; updates are applied by pulling a newer image instead. |
| `--token <YOUR_TOKEN>` | Uses a remotely-managed tunnel token; configuration lives in the Cloudflare dashboard. |

## Day-to-day management

```sh
# View connector logs (connection status, requests, errors)
docker logs -f cloudflared

# Stop / start / restart the connector
docker stop cloudflared
docker start cloudflared
docker restart cloudflared

# Remove the container (the tunnel itself stays in the Cloudflare dashboard)
docker rm -f cloudflared

# Upgrade to the newest image
docker pull cloudflare/cloudflared:latest
docker rm -f cloudflared
#   then re-run the original `docker run ...` command
```

## Verifying the tunnel

1. `docker logs cloudflared` should show lines like `Registered tunnel connection` with several edge locations.
2. In the Zero Trust dashboard, the tunnel status turns **Healthy**.
3. Visit the public hostname you configured — it should reach the internal service.

## Troubleshooting

| Symptom | Likely cause / fix |
| --- | --- |
| `Failed to determine protocol` / repeated reconnects | Outbound HTTPS (TCP 443) to Cloudflare edge is blocked. The connector needs outbound access only. |
| `token is not valid` / `Unauthorized` | Wrong or expired token. Copy the token again from the tunnel's dashboard page. |
| Tunnel shows **Down** but logs look fine | Stale dashboard state — restart the container (`docker restart cloudflared`). |
| DNS error when opening the hostname | The public hostname's CNAME record is managed by Cloudflare; confirm the hostname entry under the tunnel's **Public Hostnames** tab. |
| Service returns 502 | The tunnel is up but cannot reach the origin. Check the internal target (e.g. `http://localhost:8080`) is reachable from inside the container — use `host.docker.internal` (Docker Desktop / WSL2, or Linux Docker with `--add-host host.docker.internal:host-gateway`) instead of `localhost` when the service runs on the host. |

## Security

- **The tunnel token grants full control of the tunnel.** Anyone with the token can run a connector for that tunnel. Store it in a secret manager or environment file with restricted permissions — never commit it to git.
- Prefer passing the token via an environment variable instead of typing it in the shell history:

  ```sh
  docker run -d --name cloudflared --restart unless-stopped \
    -e TUNNEL_TOKEN=<YOUR_TOKEN> \
    cloudflare/cloudflared:latest tunnel --no-autoupdate run
  ```

- Use Cloudflare Access policies to add authentication (SSO, email OTP, etc.) in front of internal apps.
- Rotate the token from the dashboard if it may have been exposed.

## References

- Cloudflare Tunnel docs: <https://developers.cloudflare.com/cloudflare-one/connections/connect-networks/>
- cloudflared releases: <https://github.com/cloudflare/cloudflared/releases>
- Docker image: <https://hub.docker.com/r/cloudflare/cloudflared>