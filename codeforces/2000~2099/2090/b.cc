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

  vector<vector<bool>> possible(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    int j = 0;
    while (j < m && s[i][j] == '1') {
      possible[i][j] = true;
      j++;
    }
  }
  for (int j = 0; j < m; ++j) {
    int i = 0;
    while (i < n && s[i][j] == '1') {
      possible[i][j] = true;
      i++;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '1' && !possible[i][j]) {
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
