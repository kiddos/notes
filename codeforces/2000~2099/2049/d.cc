#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  i64 k = 0;
  cin >> n >> m >> k;
  vector<vector<i64>> a(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  vector<i64> dp(m);
  for (int i = 0; i < n; ++i) {
    // cout << "last row:" << endl;
    // for (int j = 0; j < m; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << endl;

    vector<i64> dp2(m, numeric_limits<i64>::max());
    for (int shift = 0; shift < m; ++shift) {
      vector<i64> dp3(m, numeric_limits<i64>::max());
      for (int j = 0; j < m; ++j) {
        i64 val = a[i][(j+shift)%m];
        if (j == 0 || i > 0) {
          dp3[j] = min(dp3[j], dp[j] + val);
        }
        if (j > 0) {
          dp3[j] = min(dp3[j], dp3[j-1] + val);
        }
      }
      for (int j = 0; j < m; ++j) {
        dp2[j] = min(dp2[j], dp3[j] + shift * k);
      }

      // cout << "row=" << i << ", shift=" << shift << endl;
      // for (int j = 0; j < m; ++j) {
      //   cout << dp3[j] + shift * k << " ";
      // }
      // cout << endl;
    }

    dp = std::move(dp2);
    // for (int j = 0; j < m; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << endl;
  }

  i64 ans = dp[m-1];
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
