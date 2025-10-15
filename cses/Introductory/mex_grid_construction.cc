#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(n));
  vector<set<int>> used(n);
  for (int r = 0; r < n; ++r) {
    set<int> can_use;
    for (int i = 0; i < n*2; ++i) {
      can_use.insert(i);
    }
    for (int c = 0; c < n; ++c) {
      for (auto it = can_use.begin(); it != can_use.end(); ++it) {
        int val = *it;
        if (!used[c].count(val)) {
          used[c].insert(val);
          ans[r][c] = val;
          can_use.erase(it);
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
