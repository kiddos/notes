#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int, 3>> edges;
  for (int i = 1; i < n; ++i) {
    array<int, 3> e;
    cin >> e[0] >> e[1];
    e[2] = i;
    edges.push_back(e);
  }

  if (n % 3 != 0) {
    cout << "-1" << endl;
    return;
  }

  vector<vector<pair<int,int>>> adj(n+1);
  for (auto& [u, v, i] : edges) {
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  vector<int> parents(n+1);
  vector<int> connects(n+1);
  vector<int> degree(n+1);
  vector<int> none_leaf(n+1);
  function<void(int,int,int)> dfs = [&](int node, int parent, int idx) {
    parents[node] = parent;
    connects[node] = idx;
    for (auto& [next_node, idx] : adj[node]) if (next_node != parent) {
      dfs(next_node, node, idx);
      degree[node]++;
      none_leaf[node] += degree[next_node] > 0;
    }
  };

  dfs(1, -1, -1);

  queue<int> q;
  for (int node = 1; node <= n; ++node) if (none_leaf[node] == 0 && degree[node] > 0) {
    q.push(node);
  }

  vector<int> ans;

  auto cut = [&](int node) -> bool {
    int p = parents[node];

    if (p == -1) return true;
    parents[node] = -1;

    ans.push_back(connects[node]);
    --degree[p];
    --none_leaf[p];
    if (degree[p]) {
      if (none_leaf[p] == 0) q.push(p);
      return true;
    }

    if (parents[p] == -1) return false;
    if (--none_leaf[parents[p]] == 0) {
      q.push(parents[p]);
    }
    return true;
  };

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();

      if (degree[node] > 2) {
        cout << "-1" << endl;
        return;
      }

      if (degree[node] == 2) {
        if (!cut(node)) {
          cout << "-1" << endl;
          return;
        }
      } else if (degree[node] == 1) {
        int p = parents[node];
        if (p == -1) {
          cout << "-1" << endl;
          return;
        }

        for (auto& [next_node, idx] : adj[p]) {
          if (next_node == parents[p]) continue;
          if (next_node == node) continue;
          if (parents[next_node] == -1) continue;

          if (degree[next_node] == 0) {
            cout << "-1" << endl;
            return;
          }

          ans.push_back(idx);
          parents[next_node] = -1;
        }

        if (!cut(p)) {
          cout << "-1" << endl;
          return;
        }
      }
    }
  }


  cout << ans.size() << endl;
  for (int val : ans) {
    cout << val << " ";
  }
  cout << endl;
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
