#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<i64>> a(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  pair<int,int> pos = {0, 0};
  vector<pair<int,int>> missing = {pos};

  for (char ch : s) {
    if (ch == 'D') {
      pos.first++;
    } else if (ch == 'R') {
      pos.second++;
    }
    missing.push_back(pos);
  }

  vector<set<pair<int,int>>> row_missing(n), col_missing(m);
  for (auto& p : missing) {
    auto [r, c] = p;
    row_missing[r].insert(p);
    col_missing[c].insert(p);
  }

  set<pair<int,int>> q;
  vector<vector<bool>> visited(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    if (row_missing[i].size() == 1) {
      auto p = *row_missing[i].begin();
      q.insert(p);
    }
  }
  for (int j = 0; j < m; ++j) {
    if (col_missing[j].size() == 1) {
      auto p = *col_missing[j].begin();
      q.insert(p);
    }
  }

  vector<i64> row_sum(n), col_sum(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      row_sum[i] += a[i][j];
      col_sum[j] += a[i][j];
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto p = *q.begin();
      q.erase(q.begin());

      // cout << p.first << "," << p.second <<endl;
      row_missing[p.first].erase(p);
      col_missing[p.second].erase(p);
      if (row_missing[p.first].size() == 0) {
        i64 sum = -row_sum[p.first];
        row_sum[p.first] += sum;
        col_sum[p.second] += sum;
        a[p.first][p.second] += sum;
      } else if (col_missing[p.second].size() == 0) {
        i64 sum = -col_sum[p.second];
        row_sum[p.first] += sum;
        col_sum[p.second] += sum;
        a[p.first][p.second] += sum;
      }

      if (row_missing[p.first].size() == 1) {
        auto p2 = *row_missing[p.first].begin();
        q.insert(p2);
      }
      if (col_missing[p.second].size() == 1) {
        auto p2 = *col_missing[p.second].begin();
        q.insert(p2);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
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
