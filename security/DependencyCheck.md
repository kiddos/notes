# DependencyCheck

- download

```sh
VERSION=$(curl -s https://jeremylong.github.io/DependencyCheck/current.txt)
curl -Ls "https://github.com/jeremylong/DependencyCheck/releases/download/v$VERSION/dependency-check-$VERSION-release.zip" --output dependency-check.zip
unzip dependency-check.zip
```

- run

```
./bin/dependency-check.sh --out . --scan .
```
