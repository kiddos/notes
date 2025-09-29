#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<vector<int>> height(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    vector<int> prefix(m);
    for (int j = 0, p = 0; j < m; ++j) {
      if (c[i][j] == '*') {
        p++;
      } else {
        p = 0;
      }
      prefix[j] = p;
    }
    vector<int> suffix(m);
    for (int j = m-1, s = 0; j >= 0; --j) {
      if (c[i][j] == '*') {
        s++;
      } else {
        s = 0;
      }
      suffix[j] = s;
    }

    for (int j = 0; j < m; ++j) {
      int top = i > 0 ? height[i-1][j] : 0;
      height[i][j] = min({top+1, prefix[j], suffix[j]});
    }
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += height[i][j];
    }
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
