#include <hiredis.h>

#include <string>
#include <iostream>

void command(redisContext* c, const std::string& command) {
  redisReply* reply = (redisReply*) redisCommand(c, command.c_str());
  if (reply->str) {
    std::cout << reply->str << std::endl;
  } else if (reply->integer) {
    std::cout << reply->integer << std::endl;
  }
  freeReplyObject(reply);
}

int main(void) {
  const std::string hostname = "localhost";
  int port = 6379;
  struct timeval timeout = {1, 500000};  // 1.5 seconds
  redisContext* c = redisConnectWithTimeout(hostname.c_str(), port, timeout);

  if (c == NULL || c->err) {
    if (c) {
      std::cerr << "Connection error: " <<  c->errstr << std::endl;
      redisFree(c);
    } else {
      std::cerr << "Connection error: can't allocation redis context" << std::endl;
    }
    return 1;
  }

  command(c, "PING");
  command(c, "SET foo bar");
  command(c, "GET foo");
  command(c, "INCR counter");
  command(c, "INCR counter");
  return 0;
}
