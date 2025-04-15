#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }
  vector<int> p(n * 2 + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      p[i+j+2] = g[i][j];
    }
  }

  set<int> s;
  for (int i = 1; i <= n * 2; ++i) {
    s.insert(i);
  }
  for (int i = 2; i <= n * 2; ++i) {
    s.erase(p[i]);
  }
  p[1] = *s.begin();

  for (int i = 1; i <= n * 2; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
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
