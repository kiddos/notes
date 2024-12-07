#include <iostream>

#include "request.h"

int main(void) {
  Request request;
  std::string response =
      request.get("https://jsonplaceholder.typicode.com/posts/1");
  std::cout << response << std::endl;

  std::string data = R"({"title": "foo", "body": "bar", "userId": 1})";
  std::unordered_map<std::string, std::string> headers = {
      {"Content-Type", "application/json"}};
  response =
      request.post("https://jsonplaceholder.typicode.com/posts", data, headers);
  std::cout << response << std::endl;
  return 0;
}
