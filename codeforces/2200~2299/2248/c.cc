#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = n * 2;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> indices(n+1);
  for (int i = 0; i < m; ++i) {
    indices[a[i]].push_back(i);
  }
  vector<int> other(m);
  for (int x = 1; x <= n; ++x) {
    int i1 = indices[x][0], i2 = indices[x][1];
    other[i1] = i2;
    other[i2] = i1;
  }

  vector<i64> dp(m+1);
  for (int i = m-1; i >= 0; --i) {
    dp[i] = dp[i+1] + 1;

    int i2 = other[i];
    if (i2 > i) {
      i64 len = i2 - i + 1;
      dp[i] = max(dp[i], dp[i2+1] + len * len);
    }
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
