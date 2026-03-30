#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<i64>> a(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  if (n == 1 && m == 1) {
    cout << -a[0][0] << endl;
    return;
  }

  vector<vector<i64>> dp1 = a;
  for (int j = 1; j < m; ++j) {
    dp1[0][j] = dp1[0][j-1] + a[0][j];
  }
  for (int i = 1; i < n; ++i) {
    dp1[i][0] = dp1[i-1][0] + a[i][0];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + a[i][j];
    }
  }

  vector<vector<i64>> dp2 = a;
  for (int j = m-2; j >= 0; --j) {
    dp2[n-1][j] = dp2[n-1][j+1] + a[n-1][j];
  }
  for (int i = n-2; i >= 0; --i) {
    dp2[i][m-1] = dp2[i+1][m-1] + a[i][m-1];
  }
  for (int i = n-2; i >= 0; --i) {
    for (int j = m-2; j >= 0; --j) {
      dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + a[i][j];
    }
  }

  constexpr i64 inf = 1e18;
  vector<i64> diag_max(n+m, -inf);
  vector<int> diag_max_count(n+m);
  vector<i64> diag_second_max(n+m, -inf);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int d = i+j;
      i64 path_sum = dp1[i][j] + dp2[i][j] - a[i][j];
      if (path_sum > diag_max[d]) {
        diag_second_max[d] = max(diag_second_max[d], diag_max[d]);
        diag_max[d] = path_sum;
        diag_max_count[d] = 1;
      } else if (path_sum == diag_max[d]) {
        diag_max_count[d]++;
      } else {
        diag_second_max[d] = max(diag_second_max[d], path_sum);
      }
    }
  }

  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << dp1[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << dp2[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  i64 ans = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      i64 sum = dp1[i][j] + dp2[i][j] - a[i][j];
      i64 after_change = sum - 2 * a[i][j];
      int d = i + j;
      if (sum == diag_max[d]) {
        // this cell belongs to the maximum path
        if (diag_max_count[d] > 1) {
          // there are multiple path that would lead to the same best sum
          ans = min(ans, max(diag_max[d], after_change));
        } else {
          // this is the only path that would lead to the same best sum
          ans = min(ans, max(diag_second_max[d], after_change));
        }
      } else {
        // not the best path
        // so the choices here are to go through the original max path
        // or go through current cell with change
        ans = min(ans, max(diag_max[d], after_change));
      }
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
