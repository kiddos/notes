#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  auto found = [&](int l) -> bool {
    vector<int> rows(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] >= l) {
          rows[j]++;
        } else {
          rows[j] = 0;
        }
      }

      int current = 0;
      for (int j = 0; j < m; ++j) {
        if (rows[j] >= l) {
          current++;
        } else {
          current = 0;
        }
        if (current >= l) {
          return true;
        }
      }
    }
    return false;
  };


  int l = 0, r = min(n, m);
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (found(mid)) {
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
