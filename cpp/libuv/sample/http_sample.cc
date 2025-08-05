#include <openssl/err.h>
#include <openssl/ssl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

#define HOST "www.google.com"
#define PATH "/"

typedef struct {
  SSL* ssl;
  BIO* read_bio;
  BIO* write_bio;
  int is_handshake_done;
  char* request_buffer;
} http_client_t;

// Global SSL context and main loop.
SSL_CTX* ssl_ctx;
uv_loop_t* loop;

uv_tcp_t client_socket;
uv_connect_t connect_req;
uv_getaddrinfo_t resolver;
http_client_t client;

// callbacks
void on_connect(uv_connect_t* req, int status);
void on_read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf);
void do_ssl_io(http_client_t* client);
void on_close(uv_handle_t* handle);

// Writes encrypted data from OpenSSL's internal BIO to the libuv socket.
void write_to_socket() {
  char encrypted_buffer[4096];
  int encrypted_bytes;
  uv_buf_t buf;
  uv_write_t* write_req;

  // Read from OpenSSL's write BIO to get encrypted data.
  while ((encrypted_bytes = BIO_read(client.write_bio, encrypted_buffer,
                                     sizeof(encrypted_buffer))) > 0) {
    // Allocate a new write request and a buffer.
    write_req = (uv_write_t*)malloc(sizeof(uv_write_t));
    if (!write_req) {
      fprintf(stderr, "Failed to allocate memory for write request\n");
      return;
    }

    buf.base = (char*)malloc(encrypted_bytes);
    if (!buf.base) {
      fprintf(stderr, "Failed to allocate memory for buffer\n");
      free(write_req);
      return;
    }
    memcpy(buf.base, encrypted_buffer, encrypted_bytes);
    buf.len = encrypted_bytes;

    // Write the encrypted data to the socket.
    uv_write(write_req, (uv_stream_t*)&client_socket, &buf, 1, NULL);
    free(buf.base);  // The buffer is copied by uv_write, so we can free it.
  }
}

// Handles the SSL handshake and subsequent data transfer.
void do_ssl_io() {
  int r;
  int error;

  // If handshake is not complete, try to continue it.
  if (!client.is_handshake_done) {
    r = SSL_connect(client.ssl);
    if (r <= 0) {
      error = SSL_get_error(client.ssl, r);
      if (error == SSL_ERROR_WANT_READ || error == SSL_ERROR_WANT_WRITE) {
        // Handshake is not finished, need to wait for more data.
        // We write whatever OpenSSL has for us and wait for a new read event.
        write_to_socket();
        return;
      } else {
        fprintf(stderr, "SSL handshake error: %s\n",
                ERR_error_string(ERR_get_error(), NULL));
        uv_close((uv_handle_t*)&client_socket, NULL);
        return;
      }
    }
    // Handshake successful.
    client.is_handshake_done = 1;
    printf("SSL Handshake successful.\n");

    // After handshake, prepare and write the HTTP request.
    const char* request_template =
        "GET %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "User-Agent: libuv-http-client\r\n"
        "Accept: */*\r\n"
        "Connection: close\r\n"
        "\r\n";
    size_t request_len = snprintf(NULL, 0, request_template, PATH, HOST);
    client.request_buffer = (char*)malloc(request_len + 1);
    if (!client.request_buffer) {
      fprintf(stderr, "Failed to allocate memory for request\n");
      uv_close((uv_handle_t*)&client_socket, NULL);
      return;
    }
    sprintf(client.request_buffer, request_template, PATH, HOST);

    // Write the HTTP request using SSL_write.
    r = SSL_write(client.ssl, client.request_buffer, request_len);
    if (r <= 0) {
      fprintf(stderr, "SSL_write error: %s\n",
              ERR_error_string(ERR_get_error(), NULL));
      free(client.request_buffer);
      uv_close((uv_handle_t*)&client_socket, NULL);
      return;
    }
    free(client.request_buffer);
    write_to_socket();
  } else {
    // Handshake is done, read the decrypted data.
    char plain_buffer[4096];
    int plain_bytes;

    while ((plain_bytes =
                SSL_read(client.ssl, plain_buffer, sizeof(plain_buffer))) > 0) {
      printf("%.*s", plain_bytes, plain_buffer);
    }

    if (plain_bytes <= 0) {
      error = SSL_get_error(client.ssl, plain_bytes);
      if (error == SSL_ERROR_WANT_READ || error == SSL_ERROR_WANT_WRITE) {
        // Not a fatal error, wait for more data.
        return;
      } else if (error == SSL_ERROR_ZERO_RETURN) {
        // Connection closed gracefully.
        uv_close((uv_handle_t*)&client_socket, on_close);
      } else {
        fprintf(stderr, "SSL read error: %s\n",
                ERR_error_string(ERR_get_error(), NULL));
        uv_close((uv_handle_t*)&client_socket, on_close);
      }
    }
  }
}

// Callback for when the read buffer needs memory.
void alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
  buf->base = (char*)malloc(suggested_size);
  buf->len = suggested_size;
}

// Callback for when data has been read from the socket.
void on_read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
  if (nread > 0) {
    // Write the raw, encrypted data from the socket into OpenSSL's read BIO.
    BIO_write(client.read_bio, buf->base, nread);
    do_ssl_io();
  } else if (nread < 0) {
    if (nread != UV_EOF) {
      fprintf(stderr, "Read error: %s\n", uv_strerror((int)nread));
    }
    // Connection closed by peer.
    uv_close((uv_handle_t*)stream, on_close);
  }
  free(buf->base);
}

// Callback for when the TCP connection is established.
void on_connect(uv_connect_t* req, int status) {
  if (status < 0) {
    fprintf(stderr, "Connect error: %s\n", uv_strerror(status));
    uv_close((uv_handle_t*)&client_socket, on_close);
    return;
  }

  // Initialize the SSL connection.
  client.ssl = SSL_new(ssl_ctx);
  if (!client.ssl) {
    fprintf(stderr, "Failed to create SSL object: %s\n",
            ERR_error_string(ERR_get_error(), NULL));
    uv_close((uv_handle_t*)&client_socket, on_close);
    return;
  }

  // Create memory BIOs for OpenSSL to manage the non-blocking I/O.
  client.read_bio = BIO_new(BIO_s_mem());
  client.write_bio = BIO_new(BIO_s_mem());
  BIO_set_nbio(client.read_bio, 1);
  BIO_set_nbio(client.write_bio, 1);
  SSL_set_bio(client.ssl, client.read_bio, client.write_bio);
  SSL_set_connect_state(client.ssl);

  // Start reading from the socket.
  uv_read_start((uv_stream_t*)&client_socket, alloc_buffer, on_read);

  // Start the SSL handshake.
  do_ssl_io();
}

// Callback for when the DNS resolution is complete.
void on_resolve(uv_getaddrinfo_t* resolver, int status, struct addrinfo* res) {
  if (status < 0) {
    fprintf(stderr, "Getaddrinfo error: %s\n", uv_strerror(status));
    return;
  }

  struct addrinfo* addr_info = res;
  while (addr_info) {
    if (addr_info->ai_family == AF_INET || addr_info->ai_family == AF_INET6) {
      break;
    }
    addr_info = addr_info->ai_next;
  }

  if (addr_info == NULL) {
    fprintf(stderr, "No suitable address found\n");
    uv_freeaddrinfo(res);
    return;
  }

  int r = uv_tcp_connect(&connect_req, &client_socket, addr_info->ai_addr,
                         on_connect);
  if (r < 0) {
    fprintf(stderr, "Connect error: %s\n", uv_strerror(r));
    uv_freeaddrinfo(res);
    return;
  }

  uv_freeaddrinfo(res);
}

// Clean up resources.
void on_close(uv_handle_t* handle) {
  if (client.ssl) {
    SSL_free(client.ssl);
  }
}

int main() {
  // Initialize OpenSSL.
  SSL_library_init();
  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();

  ssl_ctx = SSL_CTX_new(TLS_client_method());
  if (!ssl_ctx) {
    fprintf(stderr, "Failed to create SSL context: %s\n",
            ERR_error_string(ERR_get_error(), NULL));
    return 1;
  }

  client.ssl = nullptr;
  client.read_bio = nullptr;
  client.write_bio = 0;
  client.request_buffer = nullptr;

  loop = uv_default_loop();

  uv_tcp_init(loop, &client_socket);
  struct addrinfo hints;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = 0;

  // Use "https" as the service name to get port 443.
  int r = uv_getaddrinfo(loop, &resolver, on_resolve, HOST, "https", &hints);
  if (r < 0) {
    fprintf(stderr, "uv_getaddrinfo error: %s\n", uv_strerror(r));
    return 1;
  }
  return uv_run(loop, UV_RUN_DEFAULT);
}
