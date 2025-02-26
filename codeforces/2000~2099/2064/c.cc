#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> prefix(n);
  vector<i64> suffix(n);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      prefix[i] += prefix[i-1];
    }
    if (a[i] > 0) {
      prefix[i] += a[i];
    }
  }
  for (int i = n-1; i >= 0; --i) {
    if (i+1 < n) {
      suffix[i] += suffix[i+1];
    }
    if (a[i] < 0) {
      suffix[i] += a[i];
    }
  }

  i64 ans = max(-suffix[0], prefix[n-1]);
  for (int i = 0; i+1 < n; ++i) {
    ans = max(ans, prefix[i] - suffix[i+1]);
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
