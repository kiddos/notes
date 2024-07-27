#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  Solution() {
    m1_.lock();
    m2_.lock();
  }

  void first(function<void()> printFirst) {
    printFirst();
    m1_.unlock();
  }

  void second(function<void()> printSecond) {
    m1_.lock();
    printSecond();
    m1_.unlock();
    m2_.unlock();
  }

  void third(function<void()> printThird) {
    m2_.lock();
    printThird();
    m2_.unlock();
  }

 private:
  mutex m1_;
  mutex m2_;
};

void printFirst() {
  cout << "first" << endl;
}

void printSecond() {
  cout << "second" << endl;
}

void printThird() {
  cout << "third" << endl;
}

int main(void) {
  Solution s;
  thread t3(&Solution::third, &s, printThird);
  thread t2(&Solution::second, &s, printSecond);
  thread t1(&Solution::first, &s, printFirst);

  t3.join();
  t2.join();
  t1.join();
  return 0;
}
