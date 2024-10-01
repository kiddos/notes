#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  int max_idx = max_element(a.begin(), a.end()) - a.begin();
  auto robin_hood = [&](i64 x) -> bool {
    i64 total = x + sum;
    double half = (double)total / n / 2;
    int unhappy = 0;
    for (int i = 0; i < n; ++i) {
      if (i != max_idx) {
        if (a[i] < half) {
          unhappy++;
        }
      }
    }
    return unhappy > n / 2;
  };

  i64 l = 0, r = 1e16;
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (robin_hood(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
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
