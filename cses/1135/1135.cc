#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> DistanceQuery(vector<vector<int>>& adj,
                            vector<vector<int>>& query) {
    int n = adj.size();
    int l = ceil(log2(n)) + 1;

    vector<vector<int>> parent(l, vector<int>(n));
    vector<bool> visited(n);
    vector<int> depth(n);
    function<void(int)> dfs = [&](int node) {
      if (visited[node]) return;
      visited[node] = true;
      for (int child : adj[node]) {
        if (visited[child]) continue;
        parent[0][child] = node;
        depth[child] = depth[node] + 1;
        for (int j = 1; j < l; ++j) {
          parent[j][child] = parent[j - 1][parent[j - 1][child]];
        }
        dfs(child);
      }
    };
    dfs(1);

    function<int(int, int)> get_lca = [&](int a, int b) {
      if (depth[a] < depth[b]) swap(a, b);
      int diff = depth[a] - depth[b];
      for (int j = l - 1; j >= 0; --j) {
        if (diff & (1 << j)) {
          a = parent[j][a];
        }
      }
      if (a == b) return a;
      for (int j = l - 1; j >= 0; --j) {
        if (parent[j][a] != parent[j][b]) {
          a = parent[j][a];
          b = parent[j][b];
        }
      }
      return parent[0][a];
    };

    vector<int> ans;
    for (vector<int>& q : query) {
      int a = q[0], b = q[1];
      int lca = get_lca(a, b);
      int dist = depth[a] + depth[b] - 2 * depth[lca];
      ans.push_back(dist);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, q = 0;
  cin >> n >> q;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int>> query;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    query.push_back({a, b});
  }

  vector<int> ans = Solution().DistanceQuery(adj, query);
  for (int a : ans) {
    cout << a << endl;
  }
  return 0;
}
