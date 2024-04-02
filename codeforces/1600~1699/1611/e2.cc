#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(k);
  for (int i = 0; i < k; ++i) cin >> x[i];

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> blocked(n+1, -1);
  queue<int> q;
  for (int i = 0; i < k; ++i) {
    q.push(x[i]);
    blocked[x[i]] = 0;
  }
 
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      for (int next_node : adj[node]) {
        if (blocked[next_node] >= 0) continue;
        blocked[next_node] = blocked[node] + 1;
        q.push(next_node);
      }
    }
  }

  set<int> win_nodes;
  for (int node = 2; node <= n; ++node) {
    if (adj[node].size() == 1) {
      win_nodes.insert(node);
    }
  }

  function<int(int,int,int)> dfs = [&](int node, int p, int t) -> int {
    if (blocked[node] <= t) {
      return 1;
    }
    if (win_nodes.count(node)) {
      return -1;
    }

    int total = 0;
    for (int next_node : adj[node]) if (next_node != p) {
      int result = dfs(next_node, node, t+1);
      if (result < 0) {
        return result;
      }
      total += result;
    }
    return total;
  };

  int ans = dfs(1, -1, 0);
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
