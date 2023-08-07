#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;

    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    edges.push_back({u, v});
  }

  vector<int> colors(m);
  if (m == n * (n-1) / 2) {
    cout << "3" << endl;
    for (int i = 0; i < m; ++i) {
      auto [u, v] = edges[i];
      int color = 0;
      if (u == 1 || v == 1) {
        color += 1;
      }
      if (u == 2 || v == 2) {
        color += 2;
      }
      color = (color % 3) + 1;
      cout << color << " ";
    }
    cout << endl;
  } else {
    int target = 0;
    for (int node = 1; node <= n; ++node) {
      if (adj[node].size() < n-1) {
        target = node;
        break;
      }
    }

    for (auto& [next_node, index] : adj[target]) {
      colors[index] = 1;
    }

    for (int i = 0; i < m; ++i) if (!colors[i]) {
      colors[i] = 2;
    }

    cout << "2" << endl;
    for (int i = 0; i < m; ++i) cout << colors[i] << " ";
    cout << endl;
  }

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
