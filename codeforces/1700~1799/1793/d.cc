#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) cin >> q[i];

  vector<ll> left(n+1, n), right(n+1);
  for (ll i = 0; i < n; ++i) {
    left[p[i]] = min(left[p[i]], i);
    right[p[i]] = max(right[p[i]], i);
    left[q[i]] = min(left[q[i]], i);
    right[q[i]] = max(right[q[i]], i);
  }

  ll ans = 1;
  ans += (left[1] + 1) * left[1] / 2;
  ans += (n-right[1]) * (n-right[1]-1) / 2;
  ans += (right[1] - left[1]) * (right[1] - left[1]-1) / 2;

  ll L = left[1], R = right[1];
  for (int i = 2; i <= n; ++i) {
    ll l = left[i], r = right[i];
    if (l < L && r > R) {
      ans += (L - l) * (r - R);
    } else if (r < L) {
      ans += (n - R) * (L - r);
    } else if (l > R) {
      ans += (L + 1) * (l - R);
    }
    L = min(L, l);
    R = max(R, r);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
