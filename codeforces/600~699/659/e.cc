#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (x != parent_[x]) {
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

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    edges.emplace_back(x, y);
  }

  DisjointSet ds(n+1);
  for (auto [x, y] : edges) {
    ds.join(x, y);
  }

  vector<vector<int>> component(n+1);
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    component[p].push_back(i);
  }

  vector<vector<int>> adj(n+1);
  for (auto [x, y] : edges) {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> state(n+1);
  auto has_cycle = [&](const auto& self, int node, int p) -> bool {
    if (state[node]) {
      return state[node] == 1;
    }
    state[node] = 1;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      bool result = self(self, next_node, node);
      if (result) {
        return true;
      }
    }
    state[node] = 2;
    return false;
  };

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (component[i].empty()) {
      continue;
    }
    if (component[i].size() == 1) {
      ans++;
    } else {
      bool result = has_cycle(has_cycle, component[i][0], -1);
      if (!result) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
