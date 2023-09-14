#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  vector<int> stones(m);
  vector<string> ans(n, string(m, '.'));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') {
        stones[j]++;
      }

      if (s[i][j] == 'o') {
        ans[i][j] = 'o';
        for (int k = i-1; k >= 0 && stones[j] > 0; --k, stones[j]--) {
          ans[k][j] = '*';
        }
      } else if (i == n-1) {
        for (int k = i; k >= 0 && stones[j] > 0; --k, stones[j]--) {
          ans[k][j] = '*';
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
  cout << endl;
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
