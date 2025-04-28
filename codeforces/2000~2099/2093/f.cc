#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<string>> b(m, vector<string>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> b[i][j];
    }
  }

  vector<bool> possible(n);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      if (b[i][j] == a[j]) {
        possible[j] = true;
        break;
      }
    }
  }

  for (int j = 0; j < n; ++j) {
    if (!possible[j]) {
      cout << "-1" << endl;
      return;
    }
  }

  int ans = numeric_limits<int>::max();
  for (int i = 0; i < m; ++i) {
    int same = 0;
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == a[j]) {
        same++;
      }
    }
    int ops = n + (n-same) * 2;
    ans = min(ans, ops);
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
