```sh
docker pull ghcr.io/remsky/kokoro-fastapi-cpu:latest
docker rm kokoro-server
docker run --name kokoro-server -d -p 8880:8880 ghcr.io/remsky/kokoro-fastapi-cpu:latest
```
