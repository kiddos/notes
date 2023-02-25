#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> rooks;
  for (int i = 0; i < m; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    rooks.push_back({x, y});
  }

  vector<bool> rows(n+1), cols(n+1);
  for (auto [x, y] : rooks) {
    cols[x] = true;
    rows[y] = true;
  }
  for (auto [x, y] : rooks) {
    for (int r = 1; r <= n; ++r) if (r != y) {
      if (!rows[r]) {
        cout << "YES" << endl;
        return;
      }
    }
    for (int c = 1; c <= n; ++c) if (c != x) {
      if (!cols[c]) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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
