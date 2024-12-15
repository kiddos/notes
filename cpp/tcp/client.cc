#include "client.h"

#include <stdlib.h>
#include <unistd.h>

Client::Client(const std::string& server_addr, int port)
    : sock_(socket(AF_INET, SOCK_STREAM, 0)) {
  server_address_.sin_family = AF_INET;
  server_address_.sin_port = htons(port);

  if (inet_pton(AF_INET, server_addr.c_str(), &server_address_.sin_addr) <= 0) {
    perror("Invalid address or address not supported");
  }
}

Client::~Client() { close(sock_); }

bool Client::Connect() {
  if (connect(sock_, (struct sockaddr*)&server_address_,
              sizeof(server_address_)) < 0) {
    perror("Connection failed");
    return false;
  }
  return true;
}

void Client::Send(std::vector<uint8_t> data) {
  send(sock_, &data[0], data.size(), 0);
  shutdown(sock_, SHUT_WR);
  char buffer[4096];
  while (true) {
    int res = read(sock_, buffer, 4096);
    if (res < 0) {
      perror("read");
      exit(1);
    }
    if (!res) break;
  }
}
