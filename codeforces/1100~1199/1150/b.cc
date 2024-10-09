#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  auto is_empty = [&](int r, int c) -> bool {
    if (r < 0 || r >= n || c < 0 || r >= n) {
      return false;
    }
    return s[r][c] == '.';
  };

  auto fill = [&](int r, int c) -> bool {
    if (!is_empty(r, c) || !is_empty(r+1, c) || !is_empty(r+2, c) || !is_empty(r+1, c-1) || !is_empty(r+1, c+1)) {
      return false;
    }
    s[r][c] = s[r+1][c] = s[r+2][c] = s[r+1][c-1] = s[r+1][c+1] = '#';
    return true;
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '.' && !fill(i, j)) {
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

  solve();
  return 0;
}
