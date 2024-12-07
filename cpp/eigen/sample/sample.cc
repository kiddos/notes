#include <Eigen/Dense>
#include <chrono>
#include <iostream>

int main(void) {
  constexpr int SIZE = 1024;
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(SIZE, SIZE);
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(SIZE, SIZE);

  auto start = std::chrono::high_resolution_clock::now();
  Eigen::MatrixXd C = A * B;
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Time taken for multiplication: " << elapsed.count()
            << " seconds" << std::endl;
  return 0;
}
