#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<ll> p = {0};
  for (int i = 0; i < n; ++i) p.push_back(p.back() + a[i]);

  ll sum = accumulate(a.begin(), a.end(), 0LL);
  bool ans = sum % 2 == 1;

  for (int i = 0; i < q; ++i) {
    ll l = 0, r = 0, k = 0;
    cin >> l >> r >> k;
    ll range_sum = p[r] - p[l-1];
    ll new_sum = k * (r-l+1);

    if (range_sum % 2 == new_sum % 2) {
      cout << (ans ? "YES" : "NO") << endl;
    } else {
      cout << (!ans ? "YES" : "NO") << endl;
    }
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
