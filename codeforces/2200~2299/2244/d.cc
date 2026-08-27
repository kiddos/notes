#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    b[i]--;
  }
  set<int> can_flip(b.begin(), b.end());
  vector<i64> dp(2);
  for (int i = 0; i < n; ++i) {
    vector<i64> dp2(2);
    if (can_flip.count(i)) {
      dp2[0] = max(dp[0] + a[i], -dp[1] - a[i]);
      dp2[1] = min(-dp[0] - a[i], dp[1] + a[i]);
    } else {
      dp2[0] = dp[0] + a[i];
      dp2[1] = dp[1] + a[i];
    }
    dp = std::move(dp2);
  }

  i64 ans = dp[0];
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
