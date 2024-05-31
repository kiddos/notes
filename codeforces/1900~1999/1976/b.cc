#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> b(n+1);
  for (int i = 0; i < n+1; ++i) cin >> b[i];

  i64 ans = 1;
  i64 last = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    ans += abs(a[i] - b[i]);
    i64 max_val = max(a[i], b[i]);
    i64 min_val = min(a[i], b[i]);
    if (b.back() > max_val) {
      last = min(last, b.back() - max_val);
    } else if (b.back() < min_val) {
      last = min(last, min_val - b.back());
    } else {
      last = 0;
    }
  }

  ans += last;
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
