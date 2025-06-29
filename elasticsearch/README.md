```sh
docker network create elastic
docker run -d --name elasticsearch --net elastic -it -p 9200:9200 -p 9300:9300 -e "discovery.type=single-node" elasticsearch:9.0.2
curl -u elastic:password https://localhost:9200
```
