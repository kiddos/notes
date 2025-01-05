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

  vector<int> occupy, free;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      occupy.push_back(i);
    } else {
      free.push_back(i);
    }
  }

  int o = occupy.size(), f = free.size();
  if (o == 0) {
    cout << "0" << endl;
    return;
  }

  constexpr int inf = 1e9;
  vector<vector<int>> dp(o+1, vector<int>(f+1, inf));
  dp[0][0] = 0;
  for (int i = 0; i <= o; ++i) {
    for (int j = 0; j < f; ++j) {
      dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
      if (i+1 <= o) {
        int dist = abs(free[j] - occupy[i]);
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + dist);
      }
    }
  }

  int ans = dp[o][f];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
