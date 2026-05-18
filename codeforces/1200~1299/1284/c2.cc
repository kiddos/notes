#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;
  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= m;
  }


  i64 ans = 0;
  for (int len = n; len >= 1; --len) {
    i64 result = (((f[len] * f[n-len+1]) % m) * (n-len+1)) % m;
    ans += result;
    ans %= m;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
