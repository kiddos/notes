#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;

i64 extended_euclidean(i64 a, i64 b, i64 &x, i64 &y) {
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

i64 inv(i64 d) {
  i64 x = 0, y = 0;
  extended_euclidean(d, MOD, x, y);
  return ((x % MOD) + MOD) % MOD;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 special = 0, normal = 0;
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      special += a[i];
      special %= MOD;
    } else {
      normal += a[i];
      normal %= MOD;
    }
  }

  i64 alice1 = ((n - k) / 2 + 1);
  alice1 = (alice1 * k) % MOD;
  alice1 = (alice1 * inv(n - k + 1)) % MOD;
  alice1 = (alice1 * special) % MOD;
  alice1 = (alice1 * inv(k)) % MOD;
  i64 alice2 = (n - k + 1) / 2;
  alice2 = (alice2 * normal) % MOD;
  alice2 = (alice2 * inv(n - k)) % MOD;
  i64 alice = (alice1 + alice2) % MOD;

  i64 total = special + normal;
  i64 bob = total - alice;
  bob = ((bob % MOD) + MOD) % MOD;

  cout << alice << " " << bob << endl;
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
