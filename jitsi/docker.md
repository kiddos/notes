# Docker

- just follow the instruction from https://jitsi.github.io/handbook/docs/devops-guide/devops-guide-docker/

```shell
wget $(curl -s https://api.github.com/repos/jitsi/docker-jitsi-meet/releases/latest | grep 'zip' | cut -d\" -f4)
unzip stable-9909
cd stable-9909
cp env.example .env
./gen-passwords.sh
```

```shell
PUBLIC_URL=https://<ip-address>:${HTTPS_PORT}
HTTP_PORT=18000
HTTPS_PORT=18443

JVB_COLIBRI_PORT=18080
JVB_PORT=10000
JICOFO_REST_PORT=18888
```
