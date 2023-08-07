#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;

    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
  }

 private:
  vector<int> parent_, rank_;
};

bool is_k_flower(vector<int>& nodes, vector<vector<int>>& adj, vector<int>& degree) {
  int group_size = nodes.size();
  int s = sqrt(group_size);
  if (s * s != group_size) {
    return false;
  }
  int k = s;

  int in_cycle = 0, outer_cycle = 0;
  vector<int> main;
  for (int node : nodes) {
    if (degree[node] == 4) {
      in_cycle++;
      main.push_back(node);
    } else if (degree[node] == 2) {
      outer_cycle++;
    } else {
      return false;
    }
  }
  if (in_cycle != k || outer_cycle != k*k - k) {
    return false;
  }

  int n = degree.size();
  vector<bool> visited(n);
  for (int node : main) {
    visited[node] = true;
  }

  auto bfs = [&](int start) -> int {
    queue<pair<int,int>> q;
    q.push({start, 0});
    int total = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        auto [node, len] = q.front();
        q.pop();

        bool has_next = false;
        for (int next_node : adj[node]) {
          if (visited[next_node]) continue;
          visited[next_node] = true;
          q.push({next_node, len+1});
          has_next = true;
        }

        if (!has_next) {
          if (total) total++;
          total += len;
        }
      }
    }
    return total;
  };

  for (int node : main) {
    int len = bfs(node);
    // cout << "len=" << len << endl;
    if (len != k) {
      return false;
    }
  }

  return true;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  DisjointSet ds(n+1);
  vector<vector<int>> adj(n+1);
  vector<int> degree(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;

    ds.join(u, v);
    degree[u]++;
    degree[v]++;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }


  unordered_map<int, vector<int>> components;
  for (int node = 1; node <= n; ++node) {
    int p = ds.find(node);
    components[p].push_back(node);
  }

  if (components.size() != 1) {
    cout << "NO" << endl;
    return;
  }

  for (auto& [p, component] : components) {
    if (is_k_flower(component, adj, degree)) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
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
