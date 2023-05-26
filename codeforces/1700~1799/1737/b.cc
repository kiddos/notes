#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll find(ll a) {
  ll l = 1, r = 2e9;
  ll ans = l;
  while (l <= r) {
    ll m = l + (r-l) / 2;
    if (m*m <= a) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }
  return ans;
}

void solve() {
  ll l = 0, r = 0;
  cin >> l >> r;

  ll a = find(l);
  ll b = find(r);

  // cout << "a=" << a << ", b=" << b << endl;
  ll ans = max(b-a-1, 0LL) * 3;
  for (int i = 0; i < 3; ++i) {
    ll k = b * (b+i);
    if (k >= l && k <= r) {
      ans++;
    }
    if (a != b) {
      k = a * (a+i);
      if (k >= l && k <= r) {
        ans++;
      }
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
