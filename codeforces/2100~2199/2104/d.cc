#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 6e6;
vector<i64> primes;
vector<i64> prefix;

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

  prefix = {0};
  for (int p : primes) {
    prefix.push_back(prefix.back() + p);
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<i64> suffix_sum = a;
  for (int i = n-2; i >= 0; --i) {
    suffix_sum[i] += suffix_sum[i+1];
  }

  for (int i = 0; i < n; ++i) {
    int size = n - i;
    if (suffix_sum[i] >= prefix[size]) {
      cout << i << endl;
      return;
    }
  }
  cout << n << endl;
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
