#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  auto find_max_k = [&]() {
    int l = 1, r = n;
    int ans = 1;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      if (mid * (mid+1) / 2 <= n) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  int max_k = find_max_k();
  vector<vector<i64>> dp(n+1, vector<i64>(max_k+1, -1));
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = numeric_limits<int>::max();
  }
  int ans = 1;
  for (int i = n-1; i >= 0; --i) {
    for (int k = 1; k <= max_k && i+k <= n; ++k) {
      i64 subsum = p[i+k] - p[i];
      dp[i][k] = max(dp[i][k], dp[i+1][k]);
      if (subsum < dp[i+k][k-1]) {
        dp[i][k] = max(dp[i][k], subsum);
        ans = max(ans, k);
      }
    }
  }

  // for (int k = 0; k <= max_k; ++k) {
  //   for (int i = 0; i <= n; ++i) {
  //     cout << dp[i][k] << " ";
  //   }
  //   cout << endl;
  // }

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
