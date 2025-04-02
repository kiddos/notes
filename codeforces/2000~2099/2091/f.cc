#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

int find_horizontal(int d, int v) {
  int l = 0, r = d;
  int ans = l;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (mid * mid + v * v <= d * d) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  return ans;
}

vector<i64> compute_next_dp(vector<i64>& dp, int d, string& s, int v) {
  int m = dp.size();
  vector<i64> p = {0};
  for (int j = 0; j < m; ++j) {
    p.push_back(p.back() + dp[j]);
    p.back() %= MOD;
  }
  vector<i64> dp1(m);
  int d1 = find_horizontal(d, v);
  for (int j = 0; j < m; ++j) {
    if (s[j] == 'X') {
      int l = max(j - d1, 0);
      int r = min(j + d1, m-1);
      dp1[j] = p[r+1] - p[l];
      dp1[j] %= MOD;
      dp1[j] += MOD;
      dp1[j] %= MOD;
    }
  }
  return dp1;
} 

void solve() {
  int n = 0, m = 0, d = 0;
  cin >> n >> m >> d;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<i64> dp(m);
  for (int j = 0; j < m; ++j) {
    if (s[n-1][j] == 'X') {
      dp[j] += 1;
    }
  }
  dp = compute_next_dp(dp, d, s.back(), 0);

  for (int i = n-2; i >= 0; --i) {
    dp = compute_next_dp(dp, d, s[i], 1);
    dp = compute_next_dp(dp, d, s[i], 0);

    // for (int j = 0; j < m; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << endl;
  }

  i64 ans = 0;
  for (int j = 0; j < m; ++j) {
    ans += dp[j];
    ans %= MOD;
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
