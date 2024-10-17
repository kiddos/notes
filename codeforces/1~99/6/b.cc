#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  char c = '\0';
  cin >> n >> m >> c;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  unordered_set<char> deputy;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == c) {
        for (vector<int>& d : delta) {
          int r2 = i + d[0], c2 = j + d[1];
          if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && s[r2][c2] != '.' && s[r2][c2] != c) {
            deputy.insert(s[r2][c2]);
          }
        }
      }
    }
  }
  int ans = deputy.size();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
