#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void answer(vector<vector<int>>& ans) {
  for (vector<int>& row : ans) {
    for (int x : row) {
      cout << x << " ";
    }
    cout << endl;
  }
}

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<vector<array<int,3>>>> adj(n, vector<vector<array<int,3>>>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j+1 < m; ++j) {
      int x = 0;
      cin >> x;
      adj[i][j].push_back({i, j+1, x});
      adj[i][j+1].push_back({i, j, x});
    }
  }
  for (int i = 0; i+1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = 0;
      cin >> x;
      adj[i][j].push_back({i+1, j, x});
      adj[i+1][j].push_back({i, j, x});
    }
  }

  vector<vector<int>> ans(n, vector<int>(m, -1));
  if (k % 2 == 1) {
    answer(ans);
    return;
  }

  vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(k/2+1, -1)));
  function<int(int,int,int)> dfs = [&](int r, int c, int step) -> int {
    if (step == 0) {
      return 0;
    }
    if (memo[r][c][step] >= 0) {
      return memo[r][c][step];
    }

    int ans = numeric_limits<int>::max();
    for (auto [r2, c2, x] : adj[r][c]) {
      ans = min(ans, dfs(r2, c2, step-1) + x);
    }
    return memo[r][c][step] = ans;
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans[i][j] = dfs(i, j, k/2) * 2;
    }
  }
  answer(ans);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
