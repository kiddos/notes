#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <utility>

float dot(std::vector<float>& v1, std::vector<float>& v2) {
  assert(v1.size() == v2.size());
  int size = v1.size();
  float result = 0;
  for (int i = 0; i < size; ++i) {
    result += v1[i] * v2[i];
  }
  return result;
}

class SVM {
 public:
  SVM(float learning_rate, float lambda, int n_iters)
      : learning_rate_(learning_rate), lambda_(lambda), n_iters_(n_iters) {}

  void fit(std::vector<std::vector<float>>& X, std::vector<int>& Y) {
    assert(X.size() == Y.size());
    assert(X.size() > 0);

    int feature_size = X[0].size();
    w_ = std::vector<float>(feature_size);
    b_ = 0;

    int data_size = X.size();
    for (int i = 0; i < n_iters_; ++i) {
      for (int j = 0; j < data_size; ++j) {
        float val = Y[j] * dot(X[j], w_) + b_;
        if (val >= 1) {
          for (int k = 0; k < feature_size; ++k) {
            w_[k] -= learning_rate_ * 2 * lambda_ * w_[k];
          }
        } else {
          for (int k = 0; k < feature_size; ++k) {
            w_[k] -= learning_rate_ * 2 * lambda_ * (w_[k] - X[j][k] * Y[j]);
          }
          b_ -= learning_rate_ * Y[j];
        }
      }
    }
  }

  std::vector<int> predict(std::vector<std::vector<float>>& X) {
    int data_size = X.size();
    std::vector<int> pred_y;
    for (int i = 0; i < data_size; ++i) {
      float val = dot(w_, X[i]) + b_;
      pred_y.push_back(val < 0 ? -1 : 1);
    }
    return pred_y;
  }

  void debug_weights() {
    for (int k = 0; k < (int)w_.size(); ++k) {
      std::cout << w_[k] << " ";
    }
    std::cout << std::endl;
    std::cout << "b=" << b_ << std::endl;
  }

 private:
  float learning_rate_;
  float lambda_;
  int n_iters_;

  std::vector<float> w_;
  float b_;
};

std::random_device rd;
std::mt19937 gen(rd());

std::pair<float, float> generate_point(std::pair<float, float>& center,
                                       float R) {
  std::uniform_real_distribution<> dist_ang(-M_PI, M_PI);
  std::normal_distribution<> dist_r(0, R);
  float r = dist_r(gen);
  float ang = dist_ang(gen);
  float x = center.first + r * cos(ang);
  float y = center.second + r * sin(ang);
  return {x, y};
}

std::vector<std::pair<float, float>> generate_points(
    std::vector<std::pair<float, float>>& points,
    std::pair<float, float>& center, float R, int n) {
  for (int i = 0; i < n; ++i) {
    points.push_back(generate_point(center, R));
  }
  return points;
}

int main(void) {
  std::pair<float, float> c1 = {0, 1};
  std::pair<float, float> c2 = {1, 0};
  std::vector<std::pair<float, float>> points;
  std::vector<int> labels;
  constexpr int size = 1000;
  generate_points(points, c1, 0.66, size);
  for (int i = 0; i < size; ++i) {
    labels.push_back(-1);
  }
  generate_points(points, c2, 0.66, size);
  for (int i = 0; i < size; ++i) {
    labels.push_back(1);
  }

  int data_size = points.size();
  std::vector<int> indices(data_size);
  std::iota(indices.begin(), indices.end(), 0);
  std::shuffle(indices.begin(), indices.end(), gen);

  std::vector<std::vector<float>> X;
  std::vector<int> Y;
  for (int idx : indices) {
    X.push_back({points[idx].first, points[idx].second});
    Y.push_back(labels[idx]);
  }

  float learning_rate = 1e-4;
  float lambda = 1e-2;
  int n_iters = 1000;
  SVM svm(learning_rate, lambda, n_iters);
  svm.fit(X, Y);
  std::vector<int> pred_y = svm.predict(X);
  int correct = 0;
  for (int i = 0; i < (int)X.size(); ++i) {
    if (Y[i] == pred_y[i]) {
      correct++;
    }
    // std::cout << "label=" << Y[i] << ", prediction=" << pred_y[i] <<
    // std::endl;
  }
  svm.debug_weights();
  std::cout << "accuracy=" << (double)correct / X.size() * 100 << std::endl;
  return 0;
}
