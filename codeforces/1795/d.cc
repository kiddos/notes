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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n = 0;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) cin >> w[i];

  const int MOD = 998244353;
  ll ans = 1;
  for (int i = 0; i < n; i += 3) {
    vector<int> triple = {w[i], w[i+1], w[i+2]};
    sort(triple.begin(), triple.end());
    int w1 = triple[0], w2 = triple[1], w3 = triple[2];
    if (w3 == w2 && w2 == w1) {
      ans *= 3;
      ans %= MOD;
    } else if (w1 == w2) {
      ans *= 2;
      ans %= MOD;
    }
  }

  int max_val = 300000;
  vector<ll> f(max_val+1, 1);
  for (int i = 2; i <= max_val; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  vector<ll> inv_f(max_val+1);
  inv_f[max_val] = power(f[max_val], MOD-2, MOD);
  for (int i = max_val-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int n, int k) -> ll {
    ll ans = f[n] * inv_f[k];
    ans %= MOD;
    ans *= inv_f[n-k];
    ans %= MOD;
    return ans;
  };

  ans *= C(n/3, n/6);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
