#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> primes;

void precompute() {
  constexpr int MAX_P = 1000000;
  vector<bool> is_prime(MAX_P+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= MAX_P; ++p) {
    if (is_prime[p]) {
      for (int i = p * p; i <= 1000000; i += p) {
        is_prime[i] = false;
      }
    }
  }

  for (int p = 2; p <= 1000000; ++p) {
    if (is_prime[p]) {
      primes.push_back(p);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 g = a[0];
  for (int i = 0; i < n; ++i) {
    g = gcd(g, a[i]);
  }

  for (int p : primes) {
    if (gcd(p, g) == 1) {
      cout << p << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
