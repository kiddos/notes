#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto possible = [&](int x) -> bool {
    vector<int> b = a;
    int ops = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] * 2 < x) {
        b[i] = 1e9;
        ops++;
      }
    }

    int min_change = 2;
    for (int i = 1; i < n; ++i) {
      int change = (b[i-1] < x ? 1 : 0) + (b[i] < x ? 1 : 0);
      min_change = min(min_change, change);
    }
    ops += min_change;
    return ops <= k;
  };

  int l = 0, r = 1e9;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
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
