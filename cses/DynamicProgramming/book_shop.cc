#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
 
  vector<int> dp(x+1, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> dp2 = dp;
    for (int p = 0; p <= x; ++p) {
      if (dp[p] >= 0 && p + h[i] <= x) {
        dp2[p + h[i]] = max(dp2[p + h[i]], dp[p] + s[i]);
      }
    }
    dp = std::move(dp2);
  }
  int ans = *max_element(dp.begin(), dp.end());
  cout << ans << endl;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  solve();
  return 0;
}
