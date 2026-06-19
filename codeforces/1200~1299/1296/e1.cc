#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (s[j] > s[i]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  vector<int> coloring(n);
  auto dfs = [&](const auto& self, int i, int color) -> bool {
    if (coloring[i]) {
      return coloring[i] == color;
    }
    coloring[i] = color;
    for (int j : adj[i]) {
      int color2 = color == 1 ? 2 : 1;
      bool result = self(self, j, color2);
      if (!result) {
        return false;
      }
    }
    return true;
  };

  for (int i = 0; i < n; ++i) {
    if (!coloring[i]) {
      bool result = dfs(dfs, i, 1);
      if (!result) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    int color = coloring[i];
    ans.push_back(color == 1 ? '0' : '1');
  }
  cout << "YES" << endl;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
