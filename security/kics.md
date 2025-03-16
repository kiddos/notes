# kics

- build from source

```sh
git clone https://github.com/Checkmarx/kics.git
cd kics
go mod vendor
make build
```

- run

```sh
./bin/kics scan -p '<path-of-your-project-to-scan>' --report-formats json -o ./results
```
