#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (k >= 3) {
    cout << "0" << endl;
    return;
  }

  multiset<i64> s(a.begin(), a.end());
  if (k == 1) {
    i64 min_val = *s.begin();
    for (auto it = s.begin(); it != s.end(); ++it) {
      if (it != s.begin()) {
        min_val = min(min_val, *it - *prev(it));
      }
      if (next(it) != s.end()) {
        min_val = min(min_val, *next(it) - *it);
      }
    }
    cout << min_val << endl;
  } else if (k == 2) {
    i64 ans = numeric_limits<i64>::max();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (i != j) {
        i64 diff = abs(a[i] - a[j]);
        ans = min(ans, diff);

        auto it = s.lower_bound(diff);
        if (it != s.end()) {
          ans = min(ans, *it - diff);
        }
        it = s.upper_bound(diff);
        if (it != s.begin()) {
          --it;
          ans = min(ans, diff - *it);
        }
      }
    }
    cout << ans << endl;
  }
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
