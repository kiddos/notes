#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    x = x * x;
    x = x % mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  constexpr int MOD = 998244353;

  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<i64> inv_p(n+1, 1);
  for (int i = 0; i <= n; ++i) {
    inv_p[i] = power(i, MOD-2, MOD);
  }

  bool zero = false;
  i64 ans = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      if (i == 0) {
        zero = true;
      } else {
        ans *= i;
        ans %= MOD;
      }
    }
  }

  cout << (zero ? 0 : ans) << endl;

  while (m-- > 0) {
    int i = 0;
    cin >> i;
    char c = '\0';
    cin >> c;

    i--;

    if (s[i] == '?' && (c == '>' || c == '<')) {
      if (i == 0) {
        zero = false;
      } else {
        ans *= inv_p[i];
        ans %= MOD;
      }
    } else if (c == '?' && (s[i] == '>' || s[i] == '<')) {
      if (i == 0) {
        zero = true;
      } else {
        ans *= i;
        ans %= MOD;
      }
    }

    s[i] = c;
    cout << (zero ? 0 : ans) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
