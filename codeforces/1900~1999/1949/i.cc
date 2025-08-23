#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n), y(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }

  auto tangent = [&](int i1, int i2) -> bool {
    i64 dx = x[i1] - x[i2];
    i64 dy = y[i1] - y[i2];
    i64 square = dx * dx + dy * dy;
    i64 rad = r[i1] + r[i2];
    return square == rad * rad;
  };

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (tangent(i, j)) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  vector<int> colors(n);
  auto dfs = [&](const auto& self, int node, int current) -> bool {
    if (colors[node]) {
      return current == colors[node];
    }

    colors[node] = current;
    for (int next_node : adj[node]) {
      if (!self(self, next_node, -current)) {
        return false;
      }
    }
    return true;
  };

  for (int i = 0; i < n; ++i) {
    fill(colors.begin(), colors.end(), 0);
    if (dfs(dfs, i, 1)) {
      int part1 = count_if(colors.begin(), colors.end(), [&](int x) { return x == 1; });
      int part2 = count_if(colors.begin(), colors.end(), [&](int x) { return x == -1; });
      if (part1 != part2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
