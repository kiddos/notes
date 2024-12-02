#include <benchmark/benchmark.h>

#include "lib.h"

static void BM_Addition(benchmark::State &state) {
  for (auto _ : state) {
    // Code to benchmark
    int64_t result = sumto(1000000);
    benchmark::DoNotOptimize(result);
  }
}

static void BM_Addition_Parallel(benchmark::State &state) {
  for (auto _ : state) {
    // Code to benchmark
    int64_t result = sumto_opt(1000000);
    benchmark::DoNotOptimize(result);
  }
}

// Register the benchmark
BENCHMARK(BM_Addition);
BENCHMARK(BM_Addition_Parallel);

BENCHMARK_MAIN();
