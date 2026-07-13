#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<array<int,3>> ops;
  for (int i = 0; i < k; ++i) {
    array<int,3> op;
    for (int j = 0; j < 3; ++j) {
      cin >> op[j];
    }
    ops.push_back(op);
  }

  vector<pair<int,int>> rows(n), cols(m);
  int t = 1;
  for (auto op : ops) {
    if (op[0] == 1) {
      int r = op[1]-1;
      int color = op[2];
      rows[r] = {color, t};
    } else if (op[0] == 2) {
      int c = op[1]-1;
      int color = op[2];
      cols[c] = {color, t};
    }
    t++;
  }

  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rows[i].second == 0 && cols[j].second == 0) {
        continue;
      }
      if (rows[i].second > cols[j].second) {
        ans[i][j] = rows[i].first;
      } else {
        ans[i][j] = cols[j].first;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
