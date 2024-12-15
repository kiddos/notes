#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>

class Server {
 public:
  Server(int port);
  ~Server();
  void Listen();

 private:
  int server_fd_;
  struct sockaddr_in address_;
};

#endif /* end of include guard: SERVER_H */
