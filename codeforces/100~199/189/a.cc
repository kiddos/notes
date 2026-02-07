#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0, c = 0;
  cin >> n >> a >> b >> c;
  vector<int> dp(n+1, -1);
  vector<int> lens = {a, b, c};
  dp[0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int len : lens) {
      if (i -len >= 0 && dp[i-len] >= 0) {
        dp[i] = max(dp[i], dp[i-len] + 1);
      }
    }
  }
  cout << dp[n] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
