#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> carpet(n);
  for (int i = 0; i < n; ++i) cin >> carpet[i];

  string v = "vika";
  for (int j = 0, k = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (carpet[i][j] == v[k]) {
        k++;
        break;
      }
    }
    if (k == (int) v.length()) {
      cout << "YES" << endl;
      return;
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
