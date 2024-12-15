#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h>

#include <string>
#include <vector>

class Client {
 public:
  Client(const std::string& server_addr, int port);
  ~Client();
  bool Connect();
  void Send(std::vector<uint8_t> data);

 private:
  std::string server_addr_;
  int sock_;
  struct sockaddr_in server_address_;
};

#endif /* end of include guard: CLIENT_H */
