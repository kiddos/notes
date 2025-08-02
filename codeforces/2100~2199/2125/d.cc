#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, i64 n, int mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }
    n >>= 1;
    x = (x * x) % mod;
  }
  return ans;
}

void solve() {
  constexpr int MOD = 998244353;

  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> l(n), r(n), p(n), q(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> p[i] >> q[i];
  }
  vector<i64> exists(n), not_exists(n);
  for (int i = 0; i < n; ++i) {
    i64 inv_q = power(q[i], MOD-2, MOD);
    exists[i] = (p[i] * inv_q) % MOD;
    not_exists[i] = ((q[i] - p[i]) * inv_q) % MOD;
  }

  vector<i64> pref(m+1, 1);
  for (int i = 0; i < n; ++i) {
    pref[l[i]] *= not_exists[i];
    pref[l[i]] %= MOD;
  }
  for (int i = 1; i <= m; ++i) {
    pref[i] *= pref[i-1];
    pref[i] %= MOD;
  }

  vector<array<i64,4>> segments;
  for (int i = 0; i < n; ++i) {
    segments.push_back({l[i], r[i], exists[i], not_exists[i]});
  }
  sort(segments.begin(), segments.end());
  
  vector<i64> dp(m+1);
  dp[0] = 1;
  for (auto [left, right, p1, p2] : segments) {
    i64 inv_p2 = power(p2, MOD-2, MOD);
    i64 inv_prev_prob = power(pref[left-1], MOD-2, MOD);
    i64 other_not_exist = (((pref[right] * inv_prev_prob) % MOD) * inv_p2) % MOD;
    i64 prob = (((dp[left-1] * p1) % MOD) * other_not_exist) % MOD;
    dp[right] += prob;
    dp[right] %= MOD;
  }
  cout << dp[m] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
