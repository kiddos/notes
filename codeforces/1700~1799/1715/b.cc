#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n = 0, k = 0, b = 0, s = 0;
  cin >> n >> k >> b >> s;

  ll min_possible = k * b;
  ll max_possible = k * b + n * (k-1);
  // cout << "min_possible=" << min_possible << ", max_possible=" << max_possible << endl;
  if (s >= min_possible && s <= max_possible) {
    ll extra = s - k * b;
    vector<ll> a(n);
    for (int i = 0; i < n && extra > 0; ++i) {
      ll reduce = min(extra, k-1);
      a[i] += reduce;
      extra -= reduce;
    }
    a[0] += b * k;
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  } else {
    cout << "-1" << endl;
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
