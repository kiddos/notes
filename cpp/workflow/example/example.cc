#include <workflow/WFHttpServer.h>
#include <iostream>

int main(void) {
  WFHttpServer server([](WFHttpTask* task) {
    task->get_resp()->append_output_body("<html>Hello World!</html>");
  });

  std::cout << "Press ENTER to stop server..." << std::endl;
  if (server.start(8088) == 0) {
    getchar();
    server.stop();
  }
  return 0;
}
