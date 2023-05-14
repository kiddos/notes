#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  vector<ll> p = {0};
  for (int i = 0; i < n; ++i) p.push_back(p.back() + a[i]);

  ll ans = 0;
  for (int i = n; i >= 0; --i) {
    int r = n-i;
    int l = k-r;
    if (r > k) break;
    ll sum = p[i] - p[l*2];
    ans = max(ans, sum);
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
