#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> t(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  vector<pair<int,int>> queries;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    queries.emplace_back(a, b);
  }

  vector<int> path;
  vector<int> state(n+1);
  vector<vector<int>> cycles;
  auto dfs1 = [&](const auto& self, int node) -> bool {
    if (state[node]) {
      if (state[node] == 1) {
        vector<int> c;
        while (!path.empty() && path.back() != node) {
          int last = path.back();
          path.pop_back();
          c.push_back(last);
        }
        c.push_back(node);
        reverse(c.begin(), c.end());
        cycles.push_back(c);
        return true;
      }
      return false;
    }
    state[node] = 1;
    path.push_back(node);
    bool result = self(self, t[node]);
    state[node] = 2;
    return result;
  };

  for (int i = 1; i <= n; ++i) {
    if (!state[i]) {
      path.clear();
      dfs1(dfs1, i);
    }
  }

  int size = cycles.size();
  vector<int> cycle_ids(n+1);
  vector<int> cycle_length(size+1);
  vector<int> cycle_dist(n+1);
  int cycle_id = 1;
  for (vector<int>& c : cycles) {
    for (int node : c) {
      cycle_ids[node] = cycle_id;
    }
    cycle_length[cycle_id] = c.size();
    for (int i = 0; i < (int)c.size(); ++i) {
      cycle_dist[c[i]] = i;
    }
    cycle_id++;
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << cycle_ids[i] << " ";
  // }
  // cout << endl;

  vector<vector<int>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    adj[t[i]].push_back(i);
  }

  vector<int> dists_to_cycle(n+1);
  vector<int> connected_cycle_node(n+1);
  vector<int> parents(n+1);
  auto dfs2 = [&](const auto& self, int node) -> void {
    for (int prev_node : adj[node]) {
      if (cycle_ids[prev_node]) {
        continue;
      }
      dists_to_cycle[prev_node] = dists_to_cycle[node] + 1;
      connected_cycle_node[prev_node] = connected_cycle_node[node];
      parents[prev_node] = node;
      self(self, prev_node);
    }
  };

  for (int i = 1; i <= n; ++i) {
    if (cycle_ids[i]) {
      connected_cycle_node[i] = i;
      parents[i] = i;
      dfs2(dfs2, i);
    }
  }

  int L = ceil(log2(n))+1;
  vector<vector<int>> p(L, vector<int>(n+1));
  p[0] = parents;
  for (int l = 1; l < L; ++l) {
    for (int i = 1; i <= n; ++i) {
      p[l][i] = p[l-1][p[l-1][i]];
    }
  }

  auto lca = [&](int a, int b) -> int {
    if (dists_to_cycle[a] < dists_to_cycle[b]) {
      swap(a, b);
    }
    int diff = dists_to_cycle[a] - dists_to_cycle[b];
    for (int l = 0; l < L; ++l) {
      if (diff & (1<<l)) {
        a = p[l][a];
      }
    }
    if (a == b) {
      return a;
    }

    for (int l = L-1; l >= 0; --l) {
      if (p[l][a] != p[l][b]) {
        a = p[l][a];
        b = p[l][b];
      }
    }
    return p[0][a];
  };

  // for (int i = 1; i <= n; ++i) {
  //   cout << dists_to_cycle[i] << " ";
  // }
  // cout << endl;

  vector<int> ans;
  for (auto [a, b] : queries) {
    if (a == b) {
      ans.push_back(0);
      continue;
    }

    if (cycle_ids[a] && cycle_ids[b]) {
      // bot nodes are in cycle
      if (cycle_ids[a] != cycle_ids[b]) {
        ans.push_back(-1);
      } else {
        int length = cycle_dist[b] - cycle_dist[a];
        if (length < 0) {
          int cid = cycle_ids[a];
          length += cycle_length[cid];
        }
        ans.push_back(length);
      }
    } else if (cycle_ids[a] || cycle_ids[b]) {
      // one node is in a cycle
      // the source node should not be in the cycle
      if (cycle_ids[b]) {
        int cycle_node = connected_cycle_node[a];
        if (cycle_ids[cycle_node] != cycle_ids[b]) {
          ans.push_back(-1);
        } else {
          int length = cycle_dist[b] - cycle_dist[cycle_node];
          if (length < 0) {
            int cid = cycle_ids[b];
            length += cycle_length[cid];
          }
          length += dists_to_cycle[a];
          ans.push_back(length);
        }
      } else {
        ans.push_back(-1);
      }
    } else {
      // both node are in branch
      // the source node should have dist to cycle > the target node
      if (connected_cycle_node[a] != connected_cycle_node[b]) {
        ans.push_back(-1);
      } else {
        int l = lca(a, b);
        if (l != b) {
          ans.push_back(-1);
        } else {
          ans.push_back(dists_to_cycle[a] - dists_to_cycle[b]);
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
