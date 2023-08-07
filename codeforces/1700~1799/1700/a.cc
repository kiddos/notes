#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;

  if (n == 1) {
    ll ans = (m+1) * m / 2;
    cout << ans << endl;
  } else if (m == 1) {
    ll ans = (n+1) * n / 2;
    cout << ans << endl;
  } else {
    ll ans = (m+1) * m / 2 + (n * m + m) * n / 2 - m;
    cout << ans << endl;
  }
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
