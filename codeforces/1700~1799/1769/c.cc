#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int max_a = *max_element(a.begin(), a.end());
  vector<int> counts(max_a+1);
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;
  }

  vector<int> dp(max_a+3);
  for (int d = max_a; d >= 1; --d) {
    if (counts[d]) {
      dp[d] = max(dp[d], dp[d+1] + 1);
      dp[d+1] = max(dp[d+2] + 1, dp[d+1]);
      if (counts[d] > 1) {
        dp[d] = max(dp[d], dp[d+2] + 2);
      }
    }
  }

  int ans = *max_element(dp.begin(), dp.end());
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
