```sh
docker run -d --name redis-server -p 6379:6379 redis:8.2-m01-alpine
```

```sh
sudo apt-get install redis-tools
redis-cli -h localhost -p 6379
```

```sh
SET url https://www.google.com
GET url
```
