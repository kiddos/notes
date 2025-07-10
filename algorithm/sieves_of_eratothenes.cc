#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 6e6;

vector<int> primes;

void precompute() {
  vector<bool> is_prime(MAX_N+1, true);
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  for (int p : primes) {
    cout << p << " ";
  }
  cout << endl;
  cout << "number of primes: " << primes.size() << endl;
  return 0;
}
