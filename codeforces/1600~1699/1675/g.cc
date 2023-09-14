#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  reverse(a.begin()+1, a.end());

  vector<int> p = a;
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }

  constexpr int INF = 1e9;
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, INF)));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int sum = 0; sum <= m; ++sum) {
      int min_val = numeric_limits<int>::max();
      for (int last = 0; last <= m; ++last) {
        if (last+sum <= m) {
          min_val = min(min_val, dp[i-1][last][sum]);
          dp[i][last][sum+last] = min(dp[i][last][sum+last], abs(p[i] - sum - last) + min_val);
        }
      }
    }
  }

  int ans = numeric_limits<int>::max();
  for (int last = 0; last <= m; ++last) {
    ans = min(ans, dp[n][last][m]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
