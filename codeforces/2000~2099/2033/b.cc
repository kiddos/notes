#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  map<int,int> max_diag;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int d = i-j;
      if (a[i][j] < 0) {
        max_diag[d] = max(max_diag[d], abs(a[i][j]));
      }
    }
  }

  i64 ans = 0;
  for (auto& [d, depth] : max_diag) {
    ans += depth;
  }
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
