#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
  }

  i64 ans = f[n] / f[n/2] / f[n/2] * f[n/2-1] * f[n/2 - 1] / 2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
