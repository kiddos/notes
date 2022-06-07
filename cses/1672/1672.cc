#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<vector<ll>> dp(n, vector<ll>(n, numeric_limits<ll>::max()));
  for (int i = 0; i < m; ++i) {
    ll a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    dp[a-1][b-1] = min(dp[a-1][b-1], c);
    dp[b-1][a-1] = min(dp[b-1][a-1], c);
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][k] == numeric_limits<ll>::max() ||
            dp[k][j] == numeric_limits<ll>::max()) continue;

        if (dp[i][k] + dp[k][j] < dp[i][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    ll a = 0, b = 0;
    cin >> a >> b;
    if (a == b) cout << 0 << '\n';
    else if (dp[a-1][b-1] == numeric_limits<ll>::max()) cout << -1 << '\n';
    else cout << dp[a-1][b-1] << '\n';
  }
  cout.flush();
  return 0;
}
