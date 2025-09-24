- generate self-signed key

```sh
openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -sha256 -days 365
```

- let's encrypt

1. run certbot command

```sh
sudo certbot certonly --manual
```

2. start http server
3. follow certbot instrucction and create the file
