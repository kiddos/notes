#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  auto possible = [&](char color) -> bool {
    vector<bool> rows(n), cols(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == color) {
          rows[i] = true;
          cols[j] = true;
        }
      }
    }

    bool top_left = rows[0] && cols[0];
    bool top_right = rows[0] && cols[m-1];
    bool bot_left = rows[n-1] && cols[0];
    bool bot_right = rows[n-1] && cols[m-1];
    return (top_left && bot_right) || (bot_left && top_right);
  };

  bool ans = possible('W') || possible('B');
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
