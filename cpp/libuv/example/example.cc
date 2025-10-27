#include <uv.h>

#include <iostream>

static int counter = 0;

/**
 * the pseudocode of libuv
 *
 * while there are still events to process:
    e = get the next event
    if there is a callback associated with e:
        call the callback
 *
 */

void wait_for_a_while(uv_idle_t* handle) {
  counter++;
  if (counter >= 10000) uv_idle_stop(handle);
}

int main(void) {
  uv_idle_t idler;

  uv_idle_init(uv_default_loop(), &idler);
  uv_idle_start(&idler, wait_for_a_while);

  printf("Idling...\n");
  uv_run(uv_default_loop(), UV_RUN_DEFAULT);

  uv_loop_close(uv_default_loop());
  std::cout << "counter=" << counter << std::endl;
  return 0;
}
