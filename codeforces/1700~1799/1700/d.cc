#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  ll min_require = 0;
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    total += v[i];
    min_require = max(min_require, (total + i) / (i+1));
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll t = 0;
    cin >> t;
    ll ans = (total + t - 1) / t;
    if (ans > n || t < min_require) {
      cout << "-1" << endl;
    } else {
      cout << ans << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
