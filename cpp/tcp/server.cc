#include "server.h"

#include <stdlib.h>
#include <unistd.h>

#include <iostream>

Server::Server(int port) : server_fd_(socket(AF_INET, SOCK_STREAM, 0)) {
  if (server_fd_ == 0) {
    std::cerr << "fail to create socket" << std::endl;
    return;
  }

  address_.sin_family = AF_INET;
  address_.sin_addr.s_addr = INADDR_ANY;
  address_.sin_port = htons(port);

  if (bind(server_fd_, (struct sockaddr*)&address_, sizeof(address_)) < 0) {
    perror("Bind failed");
    return;
  }
}

Server::~Server() { close(server_fd_); }

void Server::Listen() {
  std::cout << "listening..." << std::endl;
  if (listen(server_fd_, 3) < 0) {
    std::cerr << "Listen failed" << std::endl;
    return;
  }

  int new_socket = 0;
  int addrlen = sizeof(address_);
  if ((new_socket = accept(server_fd_, (struct sockaddr*)&address_,
                           (socklen_t*)&addrlen)) < 0) {
    perror("Accept failed");
    return;
  }
  std::cout << "Connection Established" << std::endl;

  write(new_socket, "220 Welcome\r\n", 13);
  int bytes_read = 0;
  char buffer[4096];
  while (true) {
    int res = read(new_socket, buffer, 4096);
    if (res < 0) {
      perror("read");
      break;
    }
    if (!res) break;
    bytes_read += res;
  }
  std::cout << "bytes read: " << bytes_read << std::endl;
}
