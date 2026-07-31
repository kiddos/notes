#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  auto can_fill = [&](int r, int c) {
    for (int i = r-2; i <= r; ++i) {
      for (int j = c-2; j <= c; ++j) {
        if (i == r-1 && j == c-1) {
          continue;
        }

        if (s[i][j] == '.') {
          return false;
        }
      }
    }
    return true;
  };

  vector<string> a(n, string(m, '.'));

  auto fill = [&](int r, int c) -> void {
    for (int i = r-2; i <= r; ++i) {
      for (int j = c-2; j <= c; ++j) {
        if (i == r-1 && j == c-1) {
          continue;
        }
        a[i][j] = '#';
      }
    }
  };

  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      if (can_fill(i, j)) {
        fill(i, j);
      }
    }
  }

  if (a == s) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
