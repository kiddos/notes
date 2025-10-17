#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());

  vector<i64> dp(x+1);
  dp[0] = 1;
  constexpr int MOD = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    for (int val = 0; val < x; ++val) {
      if (val+c[i] <= x) {
        dp[val+c[i]] += dp[val];
        dp[val+c[i]] %= MOD;
      }
    }
  }
  cout << dp[x] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
