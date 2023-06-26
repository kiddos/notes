#include <bits/stdc++.h>

using namespace std;

void solve() {
  string t;
  cin >> t;
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  constexpr int MAX_VAL = 1e9;
  int m = t.length();
  vector<int> dp(m+1, MAX_VAL);
  dp[0] = 0;
  vector<int> p(m+1, -1);
  vector<int> use(m+1, -1);
  vector<int> start(m+1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int len = s[j].length();
      if (t.substr(i, len) == s[j]) {
        for (int k = 1; i+k <= m && k <= len; ++k) {
          if (dp[i]+1 < dp[i+k]) {
            dp[i+k] = dp[i]+1;
            p[i+k] = i;
            use[i+k] = j;
            start[i+k] = i+1;
          }
        }
      }
    }
  }

  int ans = dp[m];
  if (ans >= MAX_VAL) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
    int len = m;
    while (len > 0) {
      int j = use[len], st = start[len];
      cout << j+1 << " " << st << endl;

      len = p[len];
    }
  }
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
