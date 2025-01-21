#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0, y = 0;
  cin >> n >> x >> y;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 total = accumulate(a.begin(), a.end(), 0LL);
  i64 high = total - x, low = total - y;

  sort(a.begin(), a.end());
  auto at_most = [&](i64 x) -> i64 {
    // find all pairs i,j, such that a[i] + a[j] > x
    // and the answer will be n * (n-1) - that count
    i64 count = 0;
    for (int i = 0; i < n; ++i) {
      i64 missing = x + 1 - a[i];
      int c = a.end() - lower_bound(a.begin() + i+1, a.end(), missing);
      count += c;
    }
    return (i64)n * (n-1) - count;
  };

  i64 ans = at_most(high) - at_most(low - 1);
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
