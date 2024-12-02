#include "lib.h"

#include <tbb/tbb.h>

int64_t sumto(int x) {
  int64_t result = 0;
  for (int i = 1; i <= x; ++i) {
    result += i;
  }
  return result;
}

int64_t sumto_opt(int x) {
  return oneapi::tbb::parallel_reduce(
      oneapi::tbb::blocked_range<int>(1, x), 0LL,
      [](oneapi::tbb::blocked_range<int> const &r, int64_t init) -> int {
        for (int v = r.begin(); v != r.end(); v++) {
          init += v;
        }
        return init;
      },
      [](int64_t lhs, int rhs) -> int64_t { return lhs + rhs; });
}
