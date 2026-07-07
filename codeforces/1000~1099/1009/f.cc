#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    edges.emplace_back(x, y);
  }

  vector<vector<int>> adj(n+1);
  for (auto [x, y] : edges) {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<map<int,int>> d(n+1);
  vector<int> max_freq(n+1);
  vector<int> ans(n+1);
  auto dfs = [&](const auto& self, int node, int p, int depth) -> void {
    d[node][depth]++;
    max_freq[node] = depth;

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node, depth+1);

      if (d[node].size() < d[next_node].size()) {
        swap(d[node], d[next_node]);
        swap(max_freq[node], max_freq[next_node]);
      }

      for (auto [di, count] : d[next_node]) {
        d[node][di] += count;
        if (d[node][di] > d[node][max_freq[node]]) {
          max_freq[node] = di;
        } else if (d[node][di] == d[node][max_freq[node]] && di < max_freq[node]) {
          max_freq[node] = di;
        }
      }
    }
    ans[node] = max_freq[node] - depth;
  };

  dfs(dfs, 1, 1, 0);

  // for (int i = 1; i <= n; ++i) {
  //   cout << "node=" << i << " : ";
  //   for (auto [di, count] : d[i]) {
  //     cout << di << ":" << count << "  ";
  //   }
  //   cout << endl;
  // }

  for (int node = 1; node <= n; ++node) {
    cout << ans[node] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
