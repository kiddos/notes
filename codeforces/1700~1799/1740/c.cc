#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 2; i < n; ++i) {
    ans = max(ans, a[i] - a[0] + a[i] - a[i-1]);
  }
  for (int i = 0; i < n-2; ++i) {
    ans = max(ans, a.back() - a[i] + a[i+1] - a[i]);
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
