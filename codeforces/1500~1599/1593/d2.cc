#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  int h = n / 2;
  vector<map<int,int>> dp(n);
  dp[0] = {{0, 1}};
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = 1;
    for (int j = 0; j < i; ++j) {
      for (auto& [g0, len] : dp[j]) {
        int g = gcd(g0, a[i] - a[j]);
        dp[i][g] = max(dp[i][g], len+1);
      }
    }

    for (auto& [g0, len] : dp[i]) {
      if (len >= h) {
        if (g0 == 0) {
          cout << "-1" << endl;
          return;
        } else {
          ans = max(ans, g0);
        }
      }
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
