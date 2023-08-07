#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  int allmin = numeric_limits<int>::max();
  int allmax = numeric_limits<int>::min();
  vector<vector<int>> vals;
  for (int i = 0; i < n; ++i) {
    vector<int> x;
    for (int j = k; j >= 1; --j) {
      x.push_back(a[i] / j);
    }
    x.erase(unique(x.begin(), x.end()), x.end());
    vals.push_back(x);

    allmin = min(allmin, x[0]);
    allmax = max(allmax, x.back());
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int val : vals[i]) {
  //     cout << val << " ";
  //   }
  //   cout << endl;
  // }

  auto in_range = [&](int minval, int maxval) -> bool {
    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(vals[i].begin(), vals[i].end(), minval);
      if (it == vals[i].end() || *it > maxval) {
        return false;
      }
    }
    return true;
  };

  auto find = [&](int diff) -> bool {
    for (int val : vals[0]) {
      if (in_range(val, val+diff)) {
        return true;
      }
    }
    return false;
  };

  int l = 0, r = allmax - allmin;
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (find(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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
