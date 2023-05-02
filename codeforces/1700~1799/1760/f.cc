#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, d = 0;
  ll c = 0;
  cin >> n >> c >> d;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());

  auto can_achieve = [&](ll k) -> bool {
    ll total = 0;
    ll interval = k+1;
    for (int i = 0; i < d; ++i) {
      ll idx = i % interval;
      if (idx < a.size()) {
        total += a[idx];
      }
    }
    return total >= c;
  };

  ll l = 0, r = numeric_limits<int>::max();
  ll ans = -1;
  while (l <= r) {
    ll k = l + (r-l) / 2;
    if (can_achieve(k)) {
      ans = k;
      l = k+1;
    } else {
      r = k-1;
    }
  }

  if (ans < 0) {
    cout << "Impossible" << endl;
  } else if (ans == numeric_limits<int>::max()) {
    cout << "Infinity" << endl;
  } else {
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
