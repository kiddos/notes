#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> x(m), y(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
  }

  vector<vector<int>> by_x(n+1), by_y(n+1);
  for (int i = 0; i < m; ++i) {
    by_x[x[i]].push_back(i);
    by_y[y[i]].push_back(i);
  }

  int count = 0;
  vector<int> state(n+1);
  auto dfs = [&](const auto& self, int i) -> bool {
    if (state[i]) {
      return state[i] == 1;
    }
    state[i] = 1;
    count++;
    bool has_cycle = false;
    for (int idx : by_y[x[i]]) {
      if (self(self, idx)) {
        has_cycle = true;
      }
    }
    state[i] = 2;
    return has_cycle;
  };

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (x[i] == y[i]) {
      continue;
    }
    count = 0;
    if (dfs(dfs, i)) {
      ans += count + 1;
    } else {
      ans += count;
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
