# The correct way to send data using TCP

from this [blog post](https://blog.netherlabs.nl/articles/2009/01/18/the-ultimate-so_linger-page-or-why-is-my-tcp-not-reliable)

need to perform a shutdown

```c
shutdown(sock, SHUT_WR);
```

and drain the data

```c
for(;;) {
    res=read(sock, buffer, 4000);
    if(res < 0) {
        perror("reading");
        exit(1);
    }
    if(!res)
        break;
}
```

before closing the socket, or something might be weird
