#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;

  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto check = [&](int i, i64 max_val) -> bool {
    i64 val = max_val;
    i64 x = k;
    for (int j = i; j < n; ++j) {
      if (a[j] >= val) return true;
      i64 require = val - a[j];
      if (require > x) break;
      x -= require;
      if (j+1 < n && a[j+1] >= val) return true;
      val--;
    }
    return false;
  };

  auto possible = [&](i64 max_val) -> bool {
    for (int i = 0; i < n; ++i) {
      if (check(i, max_val)) return true;
    }
    return false;
  };

  i64 max_val = *max_element(a.begin(), a.end());
  i64 l = max_val, r = max_val + k;
  i64 ans = l;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
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
