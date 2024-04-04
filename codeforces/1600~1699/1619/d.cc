#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);
  
  int m = 0, n = 0;
  cin >> m >> n;
  vector<vector<int>> p(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cin >> p[i][j];
  }
  int max_val = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      max_val = max(max_val, p[i][j]);
    }
  }

  auto possible = [&](int val) -> bool {
    // each friend should have at least 1 store >= val
    for (int j = 0; j < n; ++j) {
      bool found = false;
      for (int i = 0; i < m; ++i) {
        if (p[i][j] >= val) {
          found = true;
          break;
        }
      }
      if (!found) {
        return false;
      }
    }

    // there should be a store with 2 gifts >= val
    for (int i = 0; i < m; ++i) {
      int count = 0;
      for (int j = 0; j < n; ++j) {
        count += p[i][j] >= val;
        if (count >= 2) {
          return true;
        }
      }
    }
    return false;
  };

  int l = 1, r = max_val;
  int ans = 1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
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
