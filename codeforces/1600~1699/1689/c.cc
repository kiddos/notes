#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  function<pair<int,int>(int,int)> dfs = [&](int node, int p) -> pair<int,int> {
    vector<pair<int,int>> results;
    for (int child : adj[node]) if (child != p) {
      results.push_back(dfs(child, node));
    }

    if (results.size() == 0) {
      return {1, 0};
    } else if (results.size() == 1) {
      return {results[0].first+1, results[0].first-1};
    } else {
      auto a = results[0];
      auto b = results[1];
      int save = max(a.first - 1 + b.second, b.first - 1 + a.second);
      return {a.first + b.first + 1, save};
    }
  };

  auto ans = dfs(1, -1);
  cout << ans.second << endl;
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
