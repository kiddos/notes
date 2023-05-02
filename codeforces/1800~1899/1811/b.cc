#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tape(ll x, ll y, ll n) {
  ll max_val = max(x, y);
  ll min_val = min(x, y);

  ll l = 1, r = n/2;
  ll ans = 1;
  while (l <= r) {
    ll m = l + (r-l) / 2;
    ll left = m, right = n-m+1;
    if (max_val <= right && min_val >= left) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }
  return ans;
}

void solve() {
  ll n = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  ll t1 = tape(x1, y1, n);
  ll t2 = tape(x2, y2, n);
  // cout << t1 << " " << t2 << endl;
  cout << abs(t1 - t2) << endl;
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
