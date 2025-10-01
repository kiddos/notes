#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1000000;
vector<bool> is_prime(MAX_N+1, true);
vector<int> prime_count(MAX_N+1);

void precompute() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i + i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2, c = 0; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      c++;
    }
    prime_count[i] = c;
  }
}

void solve() {
  int n = 0;
  cin >> n;

  int sq = sqrt(n);
  int prime_with_friend = prime_count[sq];
  int ans = prime_count[n] - prime_with_friend + 1;
  // 1 has no friend
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
