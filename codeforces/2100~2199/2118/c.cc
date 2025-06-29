#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ones = 0;
  vector<i64> missing;
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < 63; ++b) {
      if (a[i] & (1LL<<b)) {
        ones++;
      } else {
        missing.push_back(1LL << b);
      }
    }
  }
  sort(missing.begin(), missing.end());

  i64 ans = ones;
  for (i64 require : missing) {
    if (k >= require) {
      k -= require;
      ans++;
    } else {
      break;
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
