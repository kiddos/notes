#include <Eigen/Dense>
#include <iostream>
#include <random>
#include <vector>

#include "sample_matmul.h"

int main() {
  constexpr int SIZE = 1024;
  const int m = SIZE * SIZE;
  std::vector<float> A(m);
  std::vector<float> B(m);

  std::mt19937_64 gen;
  std::normal_distribution<float> dist;
  for (int i = 0; i < m; ++i) {
    A[i] = dist(gen);
    B[i] = dist(gen);
  }

  // Copy result from device to host
  std::vector<float> C(m);
  matmul(A.data(), B.data(), C.data(), SIZE);
  std::cout << "done" << std::endl;

  Eigen::MatrixXf d_A2(SIZE, SIZE);
  Eigen::MatrixXf d_B2(SIZE, SIZE);
  Eigen::MatrixXf d_C2(SIZE, SIZE);

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      d_A2(i, j) = A[i * SIZE + j];
      d_B2(i, j) = B[i * SIZE + j];
    }
  }

  d_C2 = d_A2 * d_B2;

  constexpr float eps = 1e-3;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (std::abs(C[i * SIZE + j] - d_C2(i, j)) > eps) {
        float v1 = C[i * SIZE + j];
        float v2 = d_C2(i, j);
        printf("Mismatch at (%d, %d): CUDA=%f, Eigen=%f\n", i, j, v1, v2);
        return 1;
      }
    }
  }

  return 0;
}
