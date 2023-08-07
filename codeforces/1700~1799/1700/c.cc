#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  ll ans = 0;
  ll pre = a[1];
  for (int i = 2; i <= n; ++i) {
    ans += abs(a[i] - a[i-1]);
    if (a[i] < a[i-1]) {
      pre += a[i] - a[i-1];
    }
  }

  cout << ans + abs(pre) << endl;
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
