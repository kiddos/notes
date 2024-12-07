#include <cpr/cpr.h>

#include <iostream>

int main(void) {
  using namespace cpr;

  cpr::Response r = cpr::Get(cpr::Url{"https://www.google.com/"});
  std::cout << r.status_code << std::endl;
  std::cout << r.header["content-type"] << std::endl;
  std::cout << r.text << std::endl;
  return 0;
}
