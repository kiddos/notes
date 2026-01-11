copy config from [application.yaml](https://raw.githubusercontent.com/hapifhir/hapi-fhir-jpaserver-starter/refs/heads/master/src/main/resources/application.yaml)

```sh
docker run -p 8080:8080 --rm --name hapi-fhir-server -v $(pwd)/config:/configs -e "--spring.config.location=file:///configs/application.yaml" hapiproject/hapi:latest
```
