#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  constexpr int MOD = 998244353;
  vector<int> factors(n+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i+i; j <= n; j += i) {
      factors[j]++;
    }
  }

  vector<i64> dp(n+1);
  dp[0] = dp[1] = 1;
  i64 prefix = 2;
  for (int i = 2; i <= n; ++i) {
    dp[i] = prefix;
    dp[i] += factors[i];
    dp[i] %= MOD;
    prefix += dp[i];
  }

  i64 ans = dp[n];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
