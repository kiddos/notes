#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = "L" + s + "L";
  int len = s.length();
  constexpr int INF = 100000000;
  vector<int> dp(len, INF);
  dp[0] = 0;
  for (int i = 0; i < len; ++i) {
    if (dp[i] < INF) {
      if (s[i] == 'L') {
        for (int j = 1; j <= m && i+j < len; ++j) {
          if (s[i+j] != 'C') {
            dp[i+j] = dp[i];
          }
        }
      } else if (s[i] == 'W') {
        if (i+1 < len && s[i+1] != 'C') {
          dp[i+1] = min(dp[i+1], dp[i] + 1);
        }
      }
    }
  }

  // cout << s << endl;
  // for (int i = 0; i < len; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  if (dp[len-1] <= k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
