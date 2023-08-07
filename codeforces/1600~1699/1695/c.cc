#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  if ((m + n) % 2 == 0) {
    cout << "NO" << endl;
    return;
  }

  vector<vector<int>> dp1 = a;
  vector<vector<int>> dp2 = a;
  for (int i = 2; i <= n; ++i) {
    dp1[i][1] = dp1[i-1][1] + a[i][1];
    dp2[i][1] = dp2[i-1][1] + a[i][1];
  }
  for (int j = 2; j <= m; ++j) {
    dp1[1][j] = dp1[1][j-1] + a[1][j];
    dp2[1][j] = dp2[1][j-1] + a[1][j];
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      dp1[i][j] = max(dp1[i][j-1], dp1[i-1][j]) + a[i][j];
      dp2[i][j] = min(dp2[i][j-1], dp2[i-1][j]) + a[i][j];
    }
  }

  if (dp1[n][m] >= 0 && dp2[n][m] <= 0 && dp1[n][m] % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
