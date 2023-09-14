#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> suffix(n);
  for (int i = n-2; i >= 0; --i) {
    suffix[i] = suffix[i+1];
    suffix[i] += a[i] >= a[i+1];
  }

  vector<int> prefix(n, 1);
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i-1];
    prefix[i] += a[i] >= a[i-1];
  }

  // make prefix negative and strict increasing
  int ans = min(suffix[0], prefix[n-1]);
  for (int i = 1; i < n; ++i) {
    ans = min(ans, prefix[i-1] + suffix[i]);
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
