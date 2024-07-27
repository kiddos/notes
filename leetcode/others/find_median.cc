#include <bits/stdc++.h>

using namespace std;


// array = [1, 2, m, 4, 5]
// array = [1, 2, m, 4]
class MedianFinder1 {
 public:
  void addNum(int num) {
    data_.insert(num);
    int n = data_.size();
    if (n == 1) mid_ = data_.begin();
    else if (num < (*mid_)) mid_ = n % 2 == 1 ? prev(mid_) : mid_;
    else mid_ = n % 2 == 0 ? next(mid_) : mid_;
  }

  double findMedian() {
    if (data_.size() % 2 == 1) return *mid_;
    return ((*mid_) + (*prev(mid_))) * 0.5;
  }

 private:
  multiset<int> data_;
  multiset<int>::iterator mid_;
};

// array = [1, 2, m, 4, 5]
// array = [1, m, 3, 4]
class MedianFinder2 {
 public:
  void addNum(int num) {
    data_.insert(num);
    int n = data_.size();
    if (n == 1) mid_ = data_.begin();
    else if (num < (*mid_)) mid_ = n % 2 == 0 ? prev(mid_) : mid_;
    else mid_ = n % 2 == 1 ? next(mid_) : mid_;
  }

  double findMedian() {
    if (data_.size() % 2 == 1) return *mid_;
    return ((*mid_) + (*next(mid_))) * 0.5;
  }

 private:
  multiset<int> data_;
  multiset<int>::iterator mid_;
};

int main(void) {
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  constexpr int n = 1000;
  uniform_int_distribution<int> dist(0, 1000);
  MedianFinder1 m1;
  MedianFinder2 m2;
  for (int i = 0; i < n; ++i) {
    int num = dist(gen);
    m1.addNum(num);
    m2.addNum(num);
    assert(m1.findMedian() == m2.findMedian());
  }
  return 0;
}
