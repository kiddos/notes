#include "client.h"

int main() {
  Client client("127.0.0.1", 20001);
  client.Connect();
  std::vector<uint8_t> data(1000000);
  client.Send(data);
  return 0;
}
