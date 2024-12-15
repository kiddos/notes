#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<vector<int>> p(n+1, vector<int>(26));
  for (int i = 0; i < n; ++i) {
    p[i+1][s[i]-'a']++;
  }
  for (int c = 0; c < 26; ++c) {
    for (int i = 1; i <= n; ++i) {
      p[i][c] += p[i-1][c];
    }
  }

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    i64 total = 0;
    for (int c = 0; c < 26; ++c) {
      total += (i64)(p[r][c] - p[l-1][c]) * (c+1);
    }
    cout << total << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
