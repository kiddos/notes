#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(n * 4) {}

  void update(int i, int tl, int tr, int index, int t) {
    if (tl == tr) {
      data_[i] = t;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (index <= tm) {
      update(i*2+1, tl, tm, index, t);
    } else {
      update(i*2+2, tm+1, tr, index, t);
    }
    data_[i] = max(data_[i*2+1], data_[i*2+2]);
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }
    if (tl > qr || tr < ql) {
      return 0;
    }
    int tm = tl + (tr - tl) / 2;
    return max(query(i*2+1, tl, tm, ql, min(qr, tm)),
               query(i*2+2, tm+1, tr, max(ql, tm+1), qr));
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> t_in(n+1), t_out(n+1);
  function<void(int,int,int&)> dfs1 = [&](int node, int parent, int& t) {
    t_in[node] = ++t;
    for (int next_node : adj[node]) if (next_node != parent) {
      dfs1(next_node, node, t);
    }
    t_out[node] = t;
  };

  int t = 0;
  dfs1(1, -1, t);

  vector<int> p(n+1);
  vector<int> p_index(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p_index[p[i]] = i;
  }

  map<int, vector<array<int,3>>> query;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0, x = 0;
    cin >> l >> r >> x;
    query[x].push_back({l, r, i});
  }

  vector<array<int, 3>> node_time;
  for (int node = 1; node <= n; ++node) {
    node_time.push_back({t_in[node], 0, node});
    node_time.push_back({t_out[node], 1, node});
  }
  sort(node_time.begin(), node_time.end());

  vector<bool> ans(q);
  SegmentTree tree(n+1);
  for (auto& [t, do_query, node] : node_time) {
    if (!do_query) {
      tree.update(0, 0, n, p_index[node], t);
    } else {
      for (auto& [l, r, i] : query[node]) {
        int max_t = tree.query(0, 0, n, l, r);
        if (max_t >= t_in[node]) {
          ans[i] = true;
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << endl;
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
