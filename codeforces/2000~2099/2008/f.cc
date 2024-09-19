#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 result = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return result;
}

i64 inv_mod(i64 d) {
  i64 x = 0, y = 0;
  extended_euclidean(d, MOD, x, y);
  return (x % MOD + MOD) % MOD; 
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> p = a;
  for (int i = 1; i < n; ++i) {
    p[i] += p[i-1];
    p[i] %= MOD;
  }

  i64 sum = 0;
  for (int i = 1; i < n; ++i) {
    sum += p[i-1] * a[i];
    sum %= MOD;
  }
  i64 d = (i64) n * (n-1) / 2;
  d %= MOD;
  sum *= inv_mod(d);
  sum %= MOD;
  cout << sum << endl;
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
