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
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<unordered_set<int>> adj(n+1);
  for (int i = 0; i < n; ++i) {
    int u = a[i], v = b[i];
    if (!adj[u].count(v)) {
      adj[u].insert(v);
    } else if (!adj[v].count(u)) {
      adj[v].insert(u);
    }
  }

  DisjointSet ds(n+1);
  for (int i = 0; i < n; ++i) {
    ds.join(a[i], b[i]);
  }

  vector<vector<int>> nodes(n+1);
  vector<int> edges(n+1);
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    nodes[p].push_back(i);
    edges[p] += adj[i].size();
  }

  vector<bool> self_loop(n+1);
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      int p = ds.find(a[i]);
      self_loop[p] = true;
    }
  }

  for (int p = 1; p <= n; ++p) {
    int node_count = nodes[p].size();
    int edge_count = edges[p];
    // cout << "node_count=" << node_count << ",edge count=" << edge_count << endl;
    if (node_count != edge_count) {
      cout << "0" << endl;
      return;
    }
  }

  i64 ans = 1;
  constexpr int MOD = 998244353;
  for (int p = 1; p <= n; ++p) {
    if (nodes[p].size() == 0) {
      continue;
    }

    if (self_loop[p]) {
      ans *= n;
    } else {
      ans *= 2;
    }
    ans %= MOD;
  }
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
