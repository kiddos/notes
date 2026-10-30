# ngrok

Public HTTPS ingress for a service running on this machine: one Docker command gives you a public
URL that forwards to a local port. Useful for demoing a local web UI or receiving webhooks without
touching the firewall.

The authtoken comes from <https://dashboard.ngrok.com/get-started/your-authtoken>; keep it in `$TOKEN`
(or `$NGROK_AUTHTOKEN`) and never commit it.

## Quick start

```sh
docker run --net=host -it -e NGROK_AUTHTOKEN=$TOKEN ngrok/ngrok:latest http https://localhost:8080
```

| Part | Meaning |
|---|---|
| `--net=host` | Container shares the host network, so `localhost:8080` refers to the host's port 8080, not a port inside the container. |
| `-it` | Interactive + TTY: the agent runs in the foreground, prints the assigned URL, and stops with `Ctrl-C`. |
| `-e NGROK_AUTHTOKEN=$TOKEN` | Passes the authtoken from the shell environment; required, and it never appears in the repo. |
| `ngrok/ngrok:latest` | Official ngrok agent v3 image. |
| `http` | Tunnel type: a public HTTPS endpoint, TLS terminated at ngrok's edge. |
| `https://localhost:8080` | Upstream URL. Here the local service itself serves TLS; use `http://localhost:8080` if it serves plain HTTP. |

Once up, the agent prints the forwarding line:

```
Forwarding  https://xxxx.ngrok-free.app -> https://localhost:8080
```

## Choosing the public URL

Without extra flags the URL is random and changes on every restart. To make it stable:

- `--url <name>.ngrok-free.app` — the one free static domain from the dashboard, e.g.
  `docker run --net=host -it -e NGROK_AUTHTOKEN=$TOKEN ngrok/ngrok:latest http --url myapp.ngrok-free.app 8080`.
- A custom/paid domain (`--url baz.ngrok.dev`) needs a domain reserved on a paid plan.

## Other tunnel types

```sh
# TCP: raw traffic forwarded to SSH on the host; the agent prints a random tcp://... address
docker run --net=host -it -e NGROK_AUTHTOKEN=$TOKEN ngrok/ngrok:latest tcp 22

# TLS passthrough for a hostname, forwarded to port 443
docker run --net=host -it -e NGROK_AUTHTOKEN=$TOKEN ngrok/ngrok:latest tls --url foo.com 443
```

## Traffic policy

Request manipulation (auth, redirects, headers, retries, ...) is done with a Traffic Policy file:

```sh
docker run --net=host -it -e NGROK_AUTHTOKEN=$TOKEN \
  -v $PWD/policy.yml:/policy.yml:ro \
  ngrok/ngrok:latest http https://localhost:8080 --traffic-policy-file /policy.yml
```

The policy file has to be mounted into the container first — `--traffic-policy-file` reads a path
*inside* the container.

## Request inspector

While the agent runs, <http://localhost:4040> serves ngrok's web UI: every request/response
(including headers and bodies) can be inspected and replayed. Handy when debugging a webhook
receiver. Keep 4040 local — it has no auth.

## Notes / gotchas

- **Docker Desktop (Windows/macOS):** `--net=host` does not expose the host loopback. Use
  `host.docker.internal` instead:
  `docker run -it -e NGROK_AUTHTOKEN=$TOKEN ngrok/ngrok:latest http https://host.docker.internal:8080`.
  Plain Linux keeps `--net=host` (or `--add-host=host.docker.internal:host-gateway`).
- The URL is printed only in the agent's output; in detached mode (`-d`) read it with
  `docker logs <container>` or the ngrok dashboard.
- The authtoken is a credential: the `start.sh` helper in this folder is git-ignored for exactly
  that reason.
- Inbound traffic arrives with the usual proxy headers (`X-Forwarded-For`, `X-Forwarded-Proto`);
  use them to recover the real client IP and scheme on the backend.