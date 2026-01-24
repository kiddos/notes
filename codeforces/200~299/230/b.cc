#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> primes;
set<i64> prime_squares;
constexpr int MAX_N = 1e6;

void precompute() {
  vector<bool> is_prime(MAX_N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= MAX_N; ++p) {
    if (is_prime[p]) {
      for (int i = p * p; i <= MAX_N; i += p)
        is_prime[i] = false;
    }
  }
  for (int p = 2; p <= MAX_N; ++p) {
    if (is_prime[p]) {
      primes.push_back(p);
    }
  }
  for (i64 p : primes) {
    prime_squares.insert(p * p);
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
    if (prime_squares.count(x[i])) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();
  solve();
  return 0;
}
