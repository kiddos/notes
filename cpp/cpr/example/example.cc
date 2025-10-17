#include <cpr/cpr.h>

#include <iostream>

int main(void) {
  cpr::Response r = cpr::Get(cpr::Url{"https://www.google.com/"});
  std::cout << r.status_code << std::endl;
  std::cout << r.header["content-type"] << std::endl;
  std::cout << r.text << std::endl;

  r = cpr::Post(cpr::Url{"http://www.httpbin.org/post"},
                cpr::Payload{{"key1", "value1"}, {"key2", "value2"}});

  std::cout << "Status Code: " << r.status_code << std::endl;
  std::cout << "Response Text (Form Data):" << std::endl;
  std::cout << r.text << std::endl;
  return 0;
}
