#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> primes;
constexpr int MAX_N = 10000000;

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

void solve() {
  int n = 0;
  cin >> n;

  i64 ans = 0;
  for (int p : primes) {
    if (p > n) {
      break;
    }
    ans += n / p;
  }
  cout << ans << endl;
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
