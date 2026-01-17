#include <google/protobuf/text_format.h>

#include "example.pb.h"

int main(void) {
  Message message;
  message.set_id(1);
  message.set_title("Message title");
  message.set_content("Message content");
  std::string prototext_output;
  google::protobuf::TextFormat::PrintToString(message, &prototext_output);
  std::cout << prototext_output << std::endl;
  return 0;
}
