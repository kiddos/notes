#define JEMALLOC_NO_DEMANGLE
#include <jemalloc/jemalloc.h>

int main(void) {
  size_t size = 1024 * 1024; // 1 MB
  void* ptr = je_malloc(size);
  je_free(ptr);
  return 0;
}
