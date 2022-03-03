#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& a, int x) {
  int n = a.size();
  vector<int> dp(n+1);
  vector<int> ans(n+1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(dp[i-1] + a[i-1], 0);
    ans[0] = max(ans[0], dp[i]);
  }

  for (int k = 1; k <= n; ++k) {
    vector<int> next_dp = dp;
    for (int i = 1; i <= n; ++i) {
      next_dp[i] = max({next_dp[i-1] + a[i-1], dp[i-1] + a[i-1] + x, 0});
      ans[k] = max(ans[k], next_dp[i]);
    }
    dp = move(next_dp);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, x = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ans = solve(a, x);
    for (int aa : ans) cout << aa << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
