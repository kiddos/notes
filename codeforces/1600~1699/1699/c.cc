#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> index(n);
  for (int i = 0; i < n; ++i) {
    index[a[i]] = i;
  }

  int l = index[0], r = index[0];
  ll ans = 1;
  for (int i = 1; i < n; ++i) {
    int idx = index[i];
    if (idx < l || idx > r) {
      l = min(l, idx);
      r = max(r, idx);
    } else {
      ll size = r-l+1 - i;
      ans *= size;
      ans %= MOD;
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
