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

  vector<vector<int>> eat(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    int evil = 0;
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'S') {
        evil++;
      }
    }
    if (evil == 0) {
      for (int j = 0; j < m; ++j) {
        eat[i][j] = 1;
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    int evil = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == 'S') {
        evil++;
      }
    }
    if (evil == 0) {
      for (int i = 0; i < n; ++i) {
        eat[i][j] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += accumulate(eat[i].begin(), eat[i].end(), 0);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
