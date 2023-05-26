#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, k = 0;
  cin >> n >> k;

  vector<ll> left(n);
  vector<ll> right(n);
  for (int i = 0; i < n; ++i) cin >> left[i];
  for (int i = 0; i < n; ++i) cin >> right[i];

  ll ans = numeric_limits<ll>::max();
  ll long_seg = 0;
  ll short_seg = 0;
  for (int i = 0; i < n; ++i) {
    ll len = right[i] - left[i] + 1;
    if (len == 1) {
      short_seg++;
    } else {
      long_seg += len;
    }

    if (long_seg + short_seg >= k) {
      ll op = right[i] + 2 * (i+1 - short_seg + max(k - long_seg, 0LL));
      ans = min(ans, op);
    }
    if (long_seg >= k) {
      ll op = right[i] - (long_seg - k) + 2 * (i+1 - short_seg);
      ans = min(ans, op);
      break;
    }
  }

  if (ans == numeric_limits<ll>::max()) {
    cout << "-1" << endl;
    return;
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
