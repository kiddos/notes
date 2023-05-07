#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int MOD = 1e9 + 7;
  int m = 64;
  vector<ll> dp(m);
  for (int i = 0; i < n; ++i) {
    vector<ll> dp2 = dp;
    for (int mask = 0; mask < m; ++mask) {
      dp2[mask&a[i]] += dp[mask];
      dp2[mask&a[i]] %= MOD;
    }
    dp2[a[i]] += 1;
    dp = move(dp2);
  }

  ll ans = 0;
  for (int i = 0; i < m; ++i) if (bitset<32>(i).count() == k) {
    ans += dp[i];
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
