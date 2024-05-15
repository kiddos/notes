#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  vector<int> found(m);
  for (int i = 0; i+1 < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (grid[i+1][j-1] == 'X' && grid[i][j] == 'X') {
        found[j]++;
      }
    }
  }
  vector<int> p = {0};
  for (int j = 0; j < m; ++j) {
    p.push_back(p.back() + found[j]);
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x1 = 0, x2 = 0;
    cin >> x1 >> x2;
    int sum = p[x2] - p[x1];
    if (sum > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
