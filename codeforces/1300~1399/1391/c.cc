#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  constexpr int MOD = 1000000007;
  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  vector<i64> p2(n+1, 1);
  for (int i = 1; i <= n; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }

  i64 ans = (f[n] - p2[n-1]) % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
