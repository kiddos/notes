#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  constexpr int MOD = 998244353;
  map<pair<int,int>, i64> dp;
  dp[{0, 0}] = 1;
  for (int i = 0; i < n; ++i) {
    map<pair<int,int>, i64> dp2;
    for (auto [state, count] : dp) {
      auto [liars, last] = state;
      if (last) {
        if (liars == a[i]) {
          dp2[{liars, 0}] += count;
          dp2[{liars, 0}] %= MOD;
        }
      } else {
        dp2[{liars+1, 1}] += count;
        dp2[{liars+1, 1}] %= MOD;
        if (liars == a[i]) {
          dp2[{liars, 0}] += count;
          dp2[{liars, 0}] %= MOD;
        }
      }
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  for (auto [state, count] : dp) {
    ans += count;
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
