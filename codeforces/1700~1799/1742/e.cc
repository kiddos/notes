#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;

  vector<ll> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<ll> p = a;
  for (int i = 1; i <= n; ++i) {
    a[i] = max(a[i], a[i-1]);
    p[i] += p[i-1];
  }

  for (int i = 0; i < q; ++i) {
    ll k = 0;
    cin >> k;

    auto it = upper_bound(a.begin(), a.end(), k);
    if (it == a.begin()) {
      cout << "0 ";
    } else {
      int idx = prev(it) - a.begin();
      cout << p[idx] << " ";
    }
  }
  cout << endl;
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
