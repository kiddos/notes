#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  auto output = [&]() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  };

  if (n == 1 && m == 1) {
    output();
    return;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vector<int> b;
      if (i > 0) b.push_back(a[i-1][j]);
      if (j > 0) b.push_back(a[i][j-1]);
      if (i+1 < n) b.push_back(a[i+1][j]);
      if (j+1 < m) b.push_back(a[i][j+1]);
      int max_val = *max_element(b.begin(), b.end());
      if (a[i][j] > max_val) {
        a[i][j] = max_val;
      }
    }
  }

  output();
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
