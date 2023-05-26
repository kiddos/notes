#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<ll> left(n), right(n);
  for (int i = n-1; i >= 0; --i) {
    right[i] = b[i] - i;
    if (i < n-1) right[i] = max(right[i], right[i+1]);
  }
  for (int i = 0; i < n; ++i) {
    left[i] = b[i] + i;
    if (i > 0) left[i] = max(left[i], left[i-1]);
  }

  // cout << "left:" << endl;
  // for (int i = 0; i < n; ++i) cout << left[i] << " ";
  // cout << endl;

  vector<ll> dp1(n), dp2(n);
  for (int i = 0; i < n-1; ++i) {
    dp1[i] = b[i] + right[i+1] + i;
  }
  for (int i = 1; i < n; ++i) {
    dp2[i] = b[i] + left[i-1] - i;
  }

  // cout << "dp:" << endl;
  // for (int i = 0; i < n; ++i) cout << dp1[i] << " ";
  // cout << endl;
  // for (int i = 0; i < n; ++i) cout << dp2[i] << " ";
  // cout << endl;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, dp1[i] + dp2[i] - b[i]);
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
