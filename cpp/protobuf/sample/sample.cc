#include "sample.pb.h"

int main(void) {
  Message message;
  message.set_id(1);
  message.set_title("Message title");
  message.set_content("Message content");
  return 0;
}
