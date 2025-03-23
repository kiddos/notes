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
  
  int rows = 0;
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = 0; j < m; ++j) {
      x ^= (s[i][j] - '0');
    }
    if (x == 1) {
      rows++;
    }
  }
  int cols = 0;
  for (int j = 0; j < m; ++j) {
    int x = 0;
    for (int i = 0; i < n; ++i) {
      x ^= (s[i][j] - '0');
    }
    if (x == 1) {
      cols++;
    }
  }
  int ans = max(rows, cols);
  cout << ans << endl;
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
