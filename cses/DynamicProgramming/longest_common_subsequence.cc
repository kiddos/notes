#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<vector<int>> dp(n+1, vector<int>(m+1));
  vector<vector<array<int,2>>> prev(n+1, vector<array<int,2>>(m+1));
  vector<array<int,2>> delta = {{-1, 0}, {0, -1}, {-1, -1}};
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        prev[i][j] = {i-1, j-1};
      } else {
        for (int d = 0; d < 3; ++d) {
          auto [di, dj] = delta[d];
          if (dp[i+di][j+dj] > dp[i][j]) {
            dp[i][j] = dp[i+di][j+dj];
            prev[i][j] = {i+di, j+dj};
          }
        }
      }
    }
  }
  array<int,2> state = {n, m};
  vector<int> ans;
  while (state[0] > 0 || state[1] > 0) {
    auto prev_state = prev[state[0]][state[1]];
    if (dp[prev_state[0]][prev_state[1]] + 1 == dp[state[0]][state[1]]) {
      ans.push_back(a[state[0]-1]);
    }
    state = prev_state;
  }
  cout << dp[n][m] << endl;
  reverse(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
