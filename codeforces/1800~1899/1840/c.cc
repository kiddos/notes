#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll ans = 0;
  for (int i = 0, window = 0; i < n; ++i) {
    if (a[i] <= q) {
      window++;
    } else {
      window = 0;
    }
    if (window >= k) {
      ans += window-k+1;
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
