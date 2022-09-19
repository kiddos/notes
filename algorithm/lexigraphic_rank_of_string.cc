#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow(ll a, int n, int MOD) {
  a %= MOD;
  ll output = 1;
  while (n) {
    if (n % 2 == 1) {
      output *= a;
      output %= MOD;
    }
    a = a * a;
    a %= MOD;
    n >>= 1;
  }
  return output;
}

ll lexigraphic_rank(const string& s) {
  int n = s.length();
  const int MOD = 1e9 + 7;

  vector<ll> f(n + 1, 1);
  vector<ll> inv_f(n + 1, 1);
  for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] * i) % MOD;
  inv_f[n] = pow(f[n], MOD - 2, MOD);
  for (int i = n - 1; i >= 1; --i) inv_f[i] = (inv_f[i + 1] * (i + 1)) % MOD;

  array<int, 26> freq = {0};
  for (int i = 0; i < n; ++i) {
    freq[s[i] - 'a']++;
  }

  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    int smaller = 0;
    for (int c2 = 0; c2 < c; ++c2) {
      smaller += freq[c2];
    }

    ll count = f[n - i - 1] * smaller;
    count %= MOD;

    for (int i = 0; i < 26; ++i) {
      count *= inv_f[freq[i]];
      count %= MOD;
    }
    freq[c]--;

    ans += count;
    ans %= MOD;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans = lexigraphic_rank("cba");
  assert(ans == 6);

  ans = lexigraphic_rank("aabaa");
  assert(ans == 3);
  return 0;
}
