#include "server.h"

int main(void) {
  Server server(20001);
  server.Listen();
  return 0;
}
