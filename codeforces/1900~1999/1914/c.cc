#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  i64 total_a = 0;
  int max_b = 0;
  i64 ans = 0;
  for (int i = 0; i < min(k, n); ++i) {
    total_a += a[i];
    max_b = max(max_b, b[i]);
    i64 b_left = k-i-1;
    if (b_left >= 0) {
      i64 total = total_a + b_left * max_b;
      ans = max(ans, total);
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
