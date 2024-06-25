#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> cave(n);
  for (int i = 0; i < n; ++i) {
    int k = 0;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int a = 0;
      cin >> a;
      cave[i].push_back(a);
    }
  }

  vector<int> require_power(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)cave[i].size(); ++j) {
      int p = cave[i][j] - j + 1;
      require_power[i] = max(require_power[i], p);
    }
  }
  vector<int> ordering(n);
  iota(ordering.begin(), ordering.end(), 0);
  sort(ordering.begin(), ordering.end(), [&](int i1, int i2) {
    return require_power[i1] < require_power[i2];
  });

  auto possible = [&](int start) -> bool {
    int p = start;
    for (int idx : ordering) {
      if (require_power[idx] > p) {
        return false;
      }
      p += cave[idx].size();
    }
    return true;
  };

  int l = require_power[ordering[0]];
  int r = require_power[ordering.back()];
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
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
