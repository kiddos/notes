#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  vector<int> rows(n), cols(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        rows[i]++;
        cols[j]++;
      }
    }
  }

  int max_val = *max_element(rows.begin(), rows.end());
  pair<int,int> r = {-1, -1}, c = {-1, -1};
  for (int i = 0; i < n; ++i) {
    if (rows[i] == max_val) {
      if (r.first < 0) r.first = i;
      r.second = i;
    }
  }
  for (int j = 0; j < m; ++j) {
    if (cols[j] == max_val) {
      if (c.first < 0) c.first = j;
      c.second = j;
    }
  }

  int row = (r.first + r.second) / 2 + 1;
  int col = (c.first + c.second) / 2 + 1;
  cout << row << " " << col << endl;
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
