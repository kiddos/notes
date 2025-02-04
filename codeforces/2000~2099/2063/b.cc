#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<i64> prefix, middle, suffix;
  for (int i = 1; i < l; ++i) {
    prefix.push_back(a[i]);
  }
  for (int i = l; i <= r; ++i) {
    middle.push_back(a[i]);
  }
  for (int i = r+1; i <= n; ++i) {
    suffix.push_back(a[i]);
  }

  auto find_min = [&](vector<i64>& middle, vector<i64>& other) -> i64 {
    vector<i64> x = middle;
    vector<i64> y = other;
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());
    int size = min(x.size(), y.size());
    for (int i = 0; i < size && y[i] < x[i]; ++i) {
      x[i] = y[i];
    }
    return accumulate(x.begin(), x.end(), 0LL);
  };

  i64 ans = min(find_min(middle, prefix), find_min(middle, suffix));
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
