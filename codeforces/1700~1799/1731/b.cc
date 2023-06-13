#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x, ll n, ll mod) {
  ll ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    n >>= 1;
    x = x * x;
    x %= mod;
  }
  return ans;
}

void solve() {
  ll n = 0;
  cin >> n;

  constexpr int MOD = 1e9 + 7;
  ll s1 = n * (n+1);
  s1 %= MOD;
  s1 *= (2 * n+1);
  s1 %= MOD;
  s1 *= power(6, MOD-2, MOD);
  // s1 /= 6;
  s1 %= MOD;

  ll s2 = n * (n-1);
  s2 %= MOD;
  s2 *= (n+1);
  s2 %= MOD;
  s2 *= power(3, MOD-2, MOD);
  s2 %= MOD;

  ll ans = (s1 + s2) % MOD;
  ans *= 2022;
  ans %= MOD;

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
