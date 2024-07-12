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

  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<pair<int,int>> c(count.begin(), count.end());

  int m = c.size();
  constexpr int INF = 100000000;
  vector<vector<int>> dp(m+1, vector<int>(m+1, INF));
  dp[0][0] = 0;

  for (int i = 1; i <= m; ++i) {
    dp[i][0] = 0;
    for (int a = 1; a <= m; ++a) {
      dp[i][a] = min(dp[i][a], dp[i-1][a]);
      int s = dp[i-1][a-1] + c[i-1].second;
      if (s <= i - a) {
        dp[i][a] = min(dp[i][a], s);
      }
    }
  }

  // for (int i = 0; i <= m; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int bob = 0;
  for (int a = 1; a <= m; ++a) {
    if (dp.back()[a] < INF) {
      bob++;
    }
  }
  int ans = m - bob;
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
