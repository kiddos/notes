#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  auto opposite = [](char ch) {
    return ch == 'W' ? 'B' : 'W';
  };

  vector<string> ans(n, string(m, '.'));
  char ch = 'W';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ans[i][j] != '.') continue;

      if (s[i][j] == 'U') {
        ans[i][j] = ch;
        ans[i+1][j] = opposite(ch);
        ch = opposite(ch);
      } else if (s[i][j] == 'D') {
        ans[i][j] = ch;
        ans[i-1][j] = opposite(ch);
        ch = opposite(ch);
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (ans[i][j] != '.') continue;

      if (s[i][j] == 'L') {
        ans[i][j] = ch;
        ans[i][j+1] = opposite(ch);
        ch = opposite(ch);
      } else if (s[i][j] == 'R') {
        ans[i][j] = ch;
        ans[i][j-1] = opposite(ch);
        ch = opposite(ch);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int color = 0;
    for (int j = 0; j < m; ++j) if (ans[i][j] != '.') {
      color += ans[i][j] == 'W' ? 1 : -1;
    }
    if (color != 0) {
      cout << "-1" << endl;
      return;
    }
  }

  for (int j = 0; j < m; ++j) {
    int color = 0;
    for (int i = 0; i < n; ++i) if (ans[i][j] != '.') {
      color += ans[i][j] == 'W' ? 1 : -1;
    }
    if (color != 0) {
      cout << "-1" << endl;
      return;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
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
