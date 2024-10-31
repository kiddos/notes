#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> prefix(n+1, vector<int>(26));
  for (int i = 0; i < n; ++i) {
    int c = s[i]- 'a';
    prefix[i+1][c]++;
  }
  for (int i = 1; i <= n; ++i) {
    for (int c = 0; c < 26; ++c) {
      prefix[i][c] += prefix[i-1][c];
    }
  }

  vector<i64> ans(26);
  for (int i = 0; i < m; ++i) {
    int p = 0;
    cin >> p;
    for (int c = 0; c < 26; ++c) {
      ans[c] += prefix[p][c];
    }
  }
  for (int c = 0; c < 26; ++c) {
    ans[c] += prefix[n][c];
  }

  for (int c = 0; c < 26; ++c) {
    cout << ans[c] << " ";
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
