#include <bits/stdc++.h>

// Find Median from Data Stream
//
// idea here is to keep 2 heap
// 1 max heap and 1 min heap
// the smaller values are max heap and larger values are min heap
// so that we can retrieve median in O(1)
// when value is added,
// we need to push this value to one of the heap
// and trasfer 1 value from this heap to the other one
// the order doesn't matter as long as we do this once for odd and even
// the goal is to keep these 2 heap the same size
// so add one at even size and the other one at odd size

using namespace std;

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() : even_(true) {}

  void addNum(int num) {
    if (even_) {
      smaller_.push(num);
      larger_.push(smaller_.top());
      smaller_.pop();
    } else {
      larger_.push(num);
      smaller_.push(larger_.top());
      larger_.pop();
    }
    even_ = !even_;
  }

  double findMedian() {
    if (even_) {
      return (smaller_.top() + larger_.top()) / 2.0;
    }
    return larger_.top();
  }

 private:
  bool even_;
  priority_queue<int> smaller_;
  priority_queue<int, vector<int>, greater<int>> larger_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  MedianFinder mf;
  mf.addNum(1);
  mf.addNum(2);
  assert(abs(mf.findMedian() - 1.5) <= 1e-6);
  mf.addNum(3);
  assert(abs(mf.findMedian() - 2.0) <= 1e-6);
  return 0;
}
