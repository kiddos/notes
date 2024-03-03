#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 each = sum / n;
  i64 total_missing = 0;
  for (int i = n-1; i >= 0; --i) {
    total_missing += a[i] - each;
    if (total_missing > 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
