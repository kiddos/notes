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
  vector<i64> dp(4);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 2) {
      dp[a[i]] += dp[a[i]];
      dp[a[i]] %= MOD;
    }
    dp[a[i]] += dp[a[i]-1];
    dp[a[i]] %= MOD;
  }
  cout << dp[3] << endl;
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
