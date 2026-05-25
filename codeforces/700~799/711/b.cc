#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<i64>> a(n, vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  pair<int,int> empty;
  vector<i64> row_sum(n), col_sum(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      row_sum[i] += a[i][j];
      col_sum[j] += a[i][j];

      if (a[i][j] == 0) {
        empty = {i, j};
      }
    }
  }

  i64 diag1 = 0, diag2 = 0;
  for (int i = 0; i < n; ++i) {
    diag1 += a[i][i];
    diag2 += a[i][n-i-1];
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i != empty.first) {
      i64 sum = row_sum[i];
      ans = sum - row_sum[empty.first];
      a[empty.first][empty.second] = ans;

      row_sum[empty.first] += ans;
      col_sum[empty.second] += ans;
      if (empty.first == empty.second) {
        diag1 += ans;
      }
      if (empty.first == n-empty.second-1) {
        diag2 += ans;
      }
      break;
    }
  }

  if (ans <= 0) {
    cout << "-1" << endl;
    return;
  }

  set<i64> sums = {diag1, diag2};
  for (int i = 0; i < n; ++i) {
    sums.insert(row_sum[i]);
    sums.insert(col_sum[i]);
  }

  if (sums.size() != 1) {
    cout << "-1" << endl;
    return;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
