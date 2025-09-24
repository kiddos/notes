- docker

```sh
docker run --name nginx-server -v $PWD/nginx.conf:/etc/nginx/nginx.conf:ro -d nginx
```
