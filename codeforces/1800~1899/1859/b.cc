#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<i64>> a;
  for (int i = 0; i < n; ++i) {
    int m = 0;
    cin >> m;
    vector<i64> row;
    for (int i = 0; i < m; ++i) {
      i64 x = 0;
      cin >> x;
      row.push_back(x);
    }

    sort(row.begin(), row.end());
    a.push_back(row);
  }

  sort(a.begin(), a.end(), [&](auto& r1, auto& r2) {
    return r1[0] < r2[0];
  });

  // move all mins to first array
  i64 first = 0;
  for (int i = 0; i < n; ++i) {
    first += a[i][0];
  }

  for (int i = 1; i < n; ++i) {
    first += a[i][1] - a[i][0];
  }
  i64 ans = first;

  // move all mins to jth array
  i64 second = 0;
  for (int i = 0; i < n; ++i) {
    second += a[i][1];
  }
  for (int j = 1; j < n; ++j) {
    i64 new_ans = second - a[j][1] + a[0][0];
    ans = max(ans, new_ans);
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
