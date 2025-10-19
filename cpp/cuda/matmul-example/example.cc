#include <benchmark/benchmark.h>

#include <Eigen/Dense>
#include <random>
#include <vector>
#include <iostream>
#include <unordered_set>

#include "matmul_example.h"

constexpr int SIZE = 1024;

class MatMulFixture : public ::benchmark::Fixture {
 public:
  std::vector<float> A, B, C;
  std::unordered_set<std::string> runs;
  Eigen::MatrixXf d_A2;
  Eigen::MatrixXf d_B2;
  Eigen::MatrixXf d_C2;

  void SetUp(const ::benchmark::State&) {
    const int m = SIZE * SIZE;
    A = std::vector<float>(m);
    B = std::vector<float>(m);
    C = std::vector<float>(m);

    std::mt19937_64 gen;
    std::normal_distribution<float> dist;
    for (int i = 0; i < m; ++i) {
      A[i] = dist(gen);
      B[i] = dist(gen);
    }

    d_A2 = Eigen::MatrixXf(SIZE, SIZE);
    d_B2 = Eigen::MatrixXf(SIZE, SIZE);
    d_C2 = Eigen::MatrixXf(SIZE, SIZE);

    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        d_A2(i, j) = A[i * SIZE + j];
        d_B2(i, j) = B[i * SIZE + j];
      }
    }
  }

  void TearDown(const ::benchmark::State&) {}
};

BENCHMARK_F(MatMulFixture, BM_MatmultCuda)(benchmark::State& state) {
  for (auto _ : state) {
    matmul(A.data(), B.data(), C.data(), SIZE);
  }
}
BENCHMARK_F(MatMulFixture, BM_MatmulEigen)(benchmark::State& state) {
  for (auto _ : state) {
    d_C2 = d_A2 * d_B2;
  }
}

BENCHMARK_MAIN();

// int main(int argc, char** argv) {
//   // 1. Initialize the library
//   ::benchmark::Initialize(&argc, argv);
//
//   // You can put global setup code here (before running benchmarks)
//   // std::cout << "Global Setup...\n";
//
//   // // 2. Run the specified benchmarks
//   // if (::benchmark::RunSpecifiedBenchmarks()) {
//   //   // 3. Run global teardown only if benchmarks were executed
//   //   globalTeardown();
//   // }
//
//   return 0;
// }

// int main() {
//
//   return 0;
// }
