# nginx

Reverse proxy with automatic HTTP→HTTPS redirect and TLS termination.
See `nginx.example.conf` for the full working configuration.

## Global settings

| Directive | Value | Meaning |
|---|---|---|
| `user` | `nginx` | Worker processes run as the `nginx` user. |
| `worker_processes` | `auto` | One worker per CPU core. |
| `error_log` | `/var/log/nginx/error.log notice` | Log level `notice` for the error log. |
| `pid` | `/var/run/nginx.pid` | Master process PID file. |
| `worker_connections` | `1024` | Max simultaneous connections per worker. |

## http block

- `include /etc/nginx/mime.types` — maps file extensions to content types.
- `log_format main` — access log line with client IP, request, status, bytes, referer, user agent, and `X-Forwarded-For`; written to `/var/log/nginx/access.log`.
- `sendfile on` — efficient file transfers (for static content).
- `keepalive_timeout 65` — keep client connections open for 65 seconds.
- `include /etc/nginx/conf.d/*.conf` — extra server configs are auto-loaded from `conf.d/`.
- `gzip` is available but commented out (`#gzip on;`).

## HTTP server (port 80)

Redirects everything to HTTPS:

```nginx
return 301 https://$host:443$request_uri;
```

## HTTPS server (port 443)

- `server_name localhost` (change to your real hostname when deploying).
- Listens on IPv4 and IPv6 (`listen [::]:443 ssl`).
- Certificate files: `/etc/nginx/ssl/fullchain.pem` and `/etc/nginx/ssl/privkey.pem`.
- TLS settings: `TLSv1.2`/`TLSv1.3` only, `HIGH:!aNULL:!MD5` ciphers, shared 1 MB session cache with a 5-minute timeout, server cipher preference enabled.

### Reverse proxy `/test/`

```nginx
location /test/ {
    proxy_pass http://host.docker.internal:8080/;
}
```

- Forwards `/test/...` to port 8080 on the host machine (`host.docker.internal` works on Docker Desktop for Windows/macOS; on plain Linux add `--add-host=host.docker.internal:host-gateway` or use the host IP).
- The trailing `/` on `proxy_pass` strips the `/test/` prefix, so `/test/api` reaches the backend as `/api`.
- Standard proxy headers are set: `Host`, `X-Real-IP`, `X-Forwarded-For`, `X-Forwarded-Proto` (so the backend knows the original client IP and that the request came over HTTPS).

### Error pages

`500 502 503 504` errors are served from `/usr/share/nginx/html/50x.html`.
A static-file `location /` block exists but is commented out — enable it to serve a website from `/usr/share/nginx/html` instead of proxying.

## Run with Docker

The config in this folder is `nginx.example.conf`; mount it as `/etc/nginx/nginx.conf`:

```sh
docker run --name nginx-server -v $PWD/nginx.example.conf:/etc/nginx/nginx.conf:ro -d nginx
```

- `:ro` mounts the config read-only.
- To apply config changes: `docker restart nginx-server`.
- Publish ports with `-p 80:80 -p 443:443` if you need to reach the proxy from outside the container.

## Notes / gotchas

- In `nginx.example.conf` the HTTP block's `server_name localhost` (line 33) is missing its trailing `;`. Add it before use or `nginx -t` will fail.
- Put the certificate/key files under `/etc/nginx/ssl/` (mount them into the container) or change the `ssl_certificate` paths.
- Test any config change with `nginx -t` before reloading.