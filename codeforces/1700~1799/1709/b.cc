#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<ll> a(n+1);

  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<ll> pref(n+2), suff(n+2);
  for (int i = 2; i <= n; ++i) {
    ll fall = 0;
    if (a[i] < a[i-1]) {
      fall = a[i-1] - a[i];
    }
    pref[i] = pref[i-1] + fall;
  }

  for (int i = n-1; i >= 1; --i) {
    ll fall = 0;
    if (a[i] < a[i+1]) {
      fall = a[i+1] - a[i];
    }
    suff[i] = suff[i+1] + fall;
  }

  for (int i = 0; i < m; ++i) {
    int s = 0, t = 0;
    cin >> s >> t;
    if (t >= s) {
      ll ans = pref[t] - pref[s];
      cout << ans << endl;
    } else {
      ll ans = suff[t] - suff[s];
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
