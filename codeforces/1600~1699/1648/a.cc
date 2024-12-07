#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> c(n, vector<int>(m));
  int max_c = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c[i][j];
      max_c = max(max_c, c[i][j]);
    }
  }

  vector<vector<int>> rows(max_c+1), cols(max_c+1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      rows[c[i][j]].push_back(i);
      cols[c[i][j]].push_back(j);
    }
  }

  i64 ans = 0;
  auto sum_dist = [&](vector<int>& indices) {
    sort(indices.begin(), indices.end());
    vector<i64> p = {0};
    int size = indices.size();
    for (int i = 0; i < size; ++i) {
      p.push_back(indices[i] + p.back());
    }
    for (int i = 0; i < size; ++i) {
      i64 prefix = (i64)i * indices[i] - p[i];
      ans += prefix;
    }
  };

  for (int c = 1; c <= max_c; ++c) {
    sum_dist(rows[c]);
  }

  for (int c = 1; c <= max_c; ++c) {
    sum_dist(cols[c]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
