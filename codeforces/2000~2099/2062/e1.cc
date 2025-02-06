#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(n * 4) {}

  int query_max(int i, int tl, int tr, int ql, int qr) {
    if (ql > qr) return 0;
    if (tr < ql || tl > qr) return 0;
    if (tl >= ql && tr <= qr) return data_[i];

    int tm = tl + (tr - tl) / 2;
    int left = query_max(i * 2 + 1, tl, tm, ql, min(tm, qr));
    int right = query_max(i * 2 + 2, tm + 1, tr, max(tm, ql), qr);
    return max(left, right);
  }

  void update(int i, int tl, int tr, int index, int val) {
    if (tl == tr) {
      data_[i] = val;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (index <= tm) {
      update(i * 2 + 1, tl, tm, index, val);
    } else {
      update(i * 2 + 2, tm + 1, tr, index, val);
    }
    data_[i] = max(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> w(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  vector<pair<int, int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n + 1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int t = 1;
  vector<int> t_in(n + 1), t_out(n + 1);
  function<void(int, int)> euler_tour = [&](int node, int p) {
    t_in[node] = t++;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      euler_tour(next_node, node);
    }
    t_out[node] = t;
  };

  euler_tour(1, 0);

  // for (int node = 1; node <= n; ++node) {
  //   cout << t_in[node] << " ";
  // }
  // cout << endl;
  // for (int node = 1; node <= n; ++node) {
  //   cout << t_out[node] << " ";
  // }
  // cout << endl;

  SegmentTree tree(t+1);
  for (int node = 1; node <= n; ++node) {
    tree.update(0, 0, t, t_in[node], w[node]);
  }

  pair<int,int> ans = {-1, -1};
  function<void(int,int)> dfs = [&](int node, int p) {
    int left = tree.query_max(0, 0, t, 0, t_in[node]-1);
    int right = tree.query_max(0, 0, t, t_out[node], t);
    int outside = max(left, right);
    // cout << "node=" << node << ", w=" << w[node] << ", outside=" << outside << endl;
    if (outside > w[node]) {
      ans = max(ans, {w[node], node});
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dfs(next_node, node);
    }
  };

  dfs(1, 0);

  if (ans.second > 0) {
    cout << ans.second << endl;
  } else {
    cout << "0" << endl;
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
