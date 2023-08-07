#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> h(n+1);
  for (int i = 1; i <= n; ++i) cin >> h[i];

  if (n % 2 == 1) {
    ll ans = 0;
    for (int i = 2; i <= n; i += 2) {
      if (h[i] <= h[i-1] || h[i] <= h[i+1]) {
        ans += max(h[i-1], h[i+1]) + 1 - h[i];
      }
    }

    cout << ans << endl;
  } else {
    vector<ll> suffix(n+3);
    for (int i = n-1; i > 1; i -= 2) {
      suffix[i] = suffix[i+2];
      if (h[i] <= h[i-1] || h[i] <= h[i+1]) {
        suffix[i] += max(h[i-1], h[i+1]) + 1 - h[i];
      }
    }

    ll ans = suffix[3];
    ll prefix = 0;
    for (int i = 2; i < n; i += 2) {
      if (h[i] <= h[i-1] || h[i] <= h[i+1]) {
        prefix += max(h[i-1], h[i+1]) + 1 - h[i];
      }
      ll total = prefix + suffix[i+3];
      ans = min(ans, total);
    }

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
