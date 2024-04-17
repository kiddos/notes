#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int sum = accumulate(a.begin(), a.end(), 0);
  vector<i64> dp(sum+1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int s = sum - a[i]; s >= 0; --s) {
      dp[s+a[i]] += dp[s];
      dp[s+a[i]] %= MOD;
    }
  }

  i64 ans = 0;
  for (int s = 1; s <= sum; ++s) {
    i64 add = (s + 1) / 2;
    add *= dp[s];
    add %= MOD;
    ans += add;
    ans %= MOD;
  }

  for (int s = 0; s <= sum; ++s) {
    for (int i = 0; i < n; ++i) if (a[i] > s) {
      i64 add = a[i] - (a[i] + s + 1) / 2;
      add *= dp[s];
      add %= MOD;
      ans += add;
      ans %= MOD;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
