# HAPI FHIR JPA Server (Docker)

Run the [HAPI FHIR JPA Server](https://hapifhir.io/) locally with Docker, using a custom
[application.yaml](https://raw.githubusercontent.com/hapifhir/hapi-fhir-jpaserver-starter/refs/heads/master/src/main/resources/application.yaml)
for configuration.

## Prerequisites

- Docker installed and running
- Port 8080 free (or change the mapping below)

## 1. Prepare the configuration

Copy the default `application.yaml` from the
[hapi-fhir-jpaserver-starter](https://github.com/hapifhir/hapi-fhir-jpaserver-starter)
repository and place it in a `config` folder next to this file:

```sh
mkdir -p config
curl -o config/application.yaml https://raw.githubusercontent.com/hapifhir/hapi-fhir-jpaserver-starter/refs/heads/master/src/main/resources/application.yaml
```

Optional edits to `config/application.yaml`:

- `server.port` — the port inside the container (keep it in sync with the `-p` mapping)
- `spring.datasource.*` — replace the default embedded database (H2/Derby) with PostgreSQL/MySQL for persistent storage
- `hapi.fhir.*` — FHIR-specific settings (validation, terminology, narrative generation, etc.)

## 2. Start the server

```sh
docker run -p 8080:8080 --rm --name hapi-fhir-server -v $(pwd)/config:/configs -e "--spring.config.location=file:///configs/application.yaml" hapiproject/hapi:latest
```

What the options mean:

| Option | Purpose |
| --- | --- |
| `-p 8080:8080` | Expose the server on <http://localhost:8080> |
| `--rm` | Remove the container automatically when it stops |
| `--name hapi-fhir-server` | Give the container a fixed name |
| `-v $(pwd)/config:/configs` | Mount the local `config` folder into the container |
| `-e "--spring.config.location=..."` | Tell Spring Boot to use the mounted `application.yaml` |
| `hapiproject/hapi:latest` | Official HAPI FHIR image |

## 3. Verify it works

- REST metadata: <http://localhost:8080/fhir/metadata>
- Web console: <http://localhost:8080/>
- Smoke test:

  ```sh
  curl http://localhost:8080/fhir/metadata | head -n 20
  ```

## 4. Stop the server

Press `Ctrl+C` in the terminal running the container, or from another terminal:

```sh
docker stop hapi-fhir-server
```

## Notes

- `--rm` means data stored in the container's embedded database is lost when the container stops.
  For real persistence, configure an external database in `config/application.yaml` and/or add a named Docker volume.
- To use a fixed image version instead of `latest`, replace `hapiproject/hapi:latest`
  with a specific tag, e.g. `hapiproject/hapi:7.4.0`.