# add a certificate

1. Generate a random certificate
```sh
openssl req -x509 -new -nodes -keyout local-ca.key -out local-ca.crt
```

or download from https website

```sh
openssl s_client -connect www.google.com:443 -showcerts </dev/null | \
awk '/BEGIN CERTIFICATE/{flag=1} /END CERTIFICATE/{print; flag=0} flag' > google_server.pem
```

2. install the CA certificate
```sh
sudo apt-get install -y ca-certificates
```

3. copy certificate
```sh
sudo cp local-ca.crt /usr/local/share/ca-certificates
```

4. update certificate
```sh
sudo update-ca-certificates
```

5. verify
```sh
sudo ls /etc/ssl/certs/ | grep local-ca
```
