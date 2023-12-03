#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  constexpr int MOD = 998244353;

  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  i64 ans = 0;
  for (int b = 0; b <= 30; ++b) {
    vector<i64> p(2), c(2);
    c[0] = 1;
    i64 total = 0;
    for (int i = 1, x = 0; i <= n; ++i) {
      if (a[i] & (1<<b)) {
        x ^= 1;
      }
      total += c[1-x] * i - p[1-x];
      total %= MOD;
      c[x]++;
      p[x] += i;
    }
    // cout << "b=" << b << " total = " << total << endl;
    ans += total * (1<<b);
    ans %= MOD;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
