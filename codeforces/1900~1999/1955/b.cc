#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0, d = 0;
  cin >> n >> c >> d;
  int m = n * n;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];
  multiset<int> s(b.begin(), b.end());

  vector<vector<int>> a;
  for (int i = 0; i < n; ++i) {
    int x = *s.begin();
    vector<int> row = {x};
    s.erase(s.begin());
    for (int i = 1; i < n; ++i) {
      auto it = s.find(x + d);
      if (it == s.end()) {
        cout << "NO" << endl;
        return;
      }
      x += d;
      row.push_back(x);
      s.erase(it);
    }
    a.push_back(row);
  }

  for (int j = 0; j < n; ++j) {
    for (int i = 1; i < n; ++i) {
      if (a[i][j] != a[i-1][j] + c) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
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
