#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0, d = 0;
  cin >> n >> m >> k >> d;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  }

  vector<i64> row(n);
  for (int i = 0; i < n; ++i) {
    vector<i64> dp(m);
    deque<int> s;
    for (int j = 0; j < m; ++j) {
      while (!s.empty() && s.front() < j-d-1) {
        s.pop_front();
      }
      i64 x = s.empty() ? 0 : dp[s.front()];
      dp[j] = x + a[i][j] + 1;

      while (!s.empty() && dp[s.back()] > dp[j]) {
        s.pop_back();
      }
      s.push_back(j);
    }
    row[i] = dp.back();
  }

  i64 ans = numeric_limits<i64>::max();
  i64 row_sum = 0;
  for (int i = 0; i < n; ++i) {
    row_sum += row[i];
    if (i >= k) {
      row_sum -= row[i-k];
    }

    if (i >= k-1) {
      ans = min(ans, row_sum);
    }
  }

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
