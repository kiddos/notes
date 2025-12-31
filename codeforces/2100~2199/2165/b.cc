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
  vector<int> count(n+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<i64> dp(n+1);
  dp[0] = 1;
  constexpr int MOD = 998244353;
  for (int i = 1; i <= n; ++i) {
    if (count[i] == 0) {
      continue;
    }

    for (int w = n; w >= count[i]; --w) {
      dp[w] += count[i] * dp[w - count[i]];
      dp[w] %= MOD;
    }
  }
  i64 ans = 0;

  int max_count = *max_element(count.begin(), count.end());
  for (int w = max_count; w <= n; ++w) {
    ans += dp[w];
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
