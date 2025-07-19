#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> primes;
constexpr int MAX_N = 30000;
void precompute() {
  vector<bool> is_prime(MAX_N+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= MAX_N; j += i) {
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
  int d = 0;
  cin >> d;
  i64 p1 = *lower_bound(primes.begin(), primes.end(), 1 + d);
  i64 p2 = *lower_bound(primes.begin(), primes.end(), p1 + d);
  i64 ans = p1 * p2;
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
