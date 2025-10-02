#include <boost/atomic.hpp>
#include <iostream>
#include <thread>
#include <vector>

boost::atomic<int> safe_counter(0);

void increment_counter() {
  for (int i = 0; i < 10000; ++i) {
    safe_counter.fetch_add(1);
  }
}

int main() {
  const int num_threads = 10;
  std::vector<std::thread> threads;

  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(increment_counter);
  }

  for (auto& t : threads) {
    t.join();
  }

  std::cout << "Final counter value: " << safe_counter.load() << std::endl;
  std::cout << "Expected final value: " << num_threads * 10000 << std::endl;

  return 0;
}
