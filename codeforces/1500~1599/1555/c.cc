#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> p = a;
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j < n; ++j) {
      p[i][j] += p[i][j-1];
    }
  }

  int ans = numeric_limits<int>::max();
  for (int j = 0; j < n; ++j) {
    int top = p[0][n-1] - p[0][j];
    int bot = j > 0 ? p[1][j-1] : 0;
    int bob = max(top, bot);
    ans = min(ans, bob);
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
