#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<ll> counts(n+1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    counts[i] = counts[i-1];
    if (i > a[i]) {
      if (a[i] > 0 && a[i] <= n) {
        ans += counts[a[i]-1];
      }
      counts[i]++;
    }
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
