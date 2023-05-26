#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll ans = numeric_limits<ll>::max();
  sort(a.begin(), a.end());
  for (int i = 2; i < n; ++i) {
    ll op = a[i-1] - a[i-2] + a[i] - a[i-1];
    ans = min(ans, op);
  }
  cout << ans << endl;
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
