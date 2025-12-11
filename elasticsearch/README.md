# start with docker

```sh
docker network create elastic
docker run -d --name es01 --net elastic -it -p 9200:9200 -p 9300:9300 -e "discovery.type=single-node" elasticsearch:9.0.2
docker pull docker.elastic.co/kibana/kibana:9.2.2
docker run --name kib01 --net elastic -p 5601:5601 docker.elastic.co/kibana/kibana:9.2.2
```

copy the password from the console log, paste into kabana when start

verify
```sh
curl -u elastic:password https://localhost:9200
```

if elasticsearch starts failed, might need this

```sh
sudo sysctl -w vm.max_map_count=262144
```

to regenerate password
```sh
docker exec -it es01 /usr/share/elasticsearch/bin/elasticsearch-reset-password -u elastic
```

to regenerate enrollment token
```sh
docker exec -it es01 /usr/share/elasticsearch/bin/elasticsearch-create-enrollment-token -s kibana
```
