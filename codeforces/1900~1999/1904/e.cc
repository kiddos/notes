#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Query {
  int index;
  vector<int> a;
};

class SegmentTree {
 public:
  SegmentTree(int n) : data_(n * 4), lazy_(n * 4) {}

  void update(int i, int tl, int tr, int l, int r, int x) {
    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      data_[i] += x;
      lazy_[i] += x;
      return;
    }

    push(i, tl, tr);

    int tm = tl + (tr - tl) / 2;
    if (tl <= tm) update(i*2+1, tl, tm, l, r, x);
    if (tr > tm) update(i*2+2, tm+1, tr, l, r, x);
    data_[i] = max(data_[i*2+1], data_[i*2+2]);
  }

  int query_max(int i, int tl, int tr, int ql, int qr) {
    if (tr < ql || tl > qr) {
      return 0;
    }

    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    push(i, tl, tr);

    int tm = tl + (tr - tl) / 2;
    return max(query_max(i*2+1, tl, tm, ql, min(qr, tm)),
               query_max(i*2+2, tm+1, tr, max(ql, tm+1), qr));
  }

 private:
  vector<int> data_, lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      if (tl != tr) {
        data_[i*2+1] += lazy_[i];
        lazy_[i*2+1] += lazy_[i];

        data_[i*2+2] += lazy_[i];
        lazy_[i*2+2] += lazy_[i];
      }
      lazy_[i] = 0;
    }
  }
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

  vector<vector<Query>> query(n+1);
  for (int i = 0; i < q; ++i) {
    int x = 0, k = 0;
    cin >> x >> k;
    vector<int> a(k);
    for (int j = 0; j < k; ++j) cin >> a[j];
    query[x].push_back(Query{i, a});
  }

  int t = 0;
  vector<int> t_in(n+1), t_out(n+1);
  function<void(int,int)> dfs1 = [&](int node, int parent) {
    t_in[node] = ++t;
    for (int next_node : adj[node]) if (next_node != parent) {
      dfs1(next_node, node);
    }
    t_out[node] = t;
  };

  dfs1(1, -1);

  SegmentTree tree(t+1);
  for (int node = 2; node <= n; ++node) {
    // cout << "node=" << node << ", in=" << t_in[node] << ", out=" << t_out[node] << endl;
    tree.update(0, 0, t, t_in[node], t_out[node], 1);
  }

  vector<int> next(n+1);
  vector<int> ans(q);
  auto process_query = [&](Query& q, int current_node) {
    vector<pair<int,int>> skips;
    for (int node : q.a) {
      if (node == current_node) {
        return;
      }

      if (t_in[node] <= t_in[current_node] && t_out[current_node] <= t_out[node]) {
        // node is ancestor
        int next_node = next[node];
        skips.emplace_back(0, t_in[next_node]-1);
        skips.emplace_back(t_out[next_node]+1, t);
      } else {
        skips.emplace_back(t_in[node], t_out[node]);
      }
    }

    sort(skips.begin(), skips.end());

    // cout << "index=" << q.index << endl;
    int prev = 0;
    for (auto& [l, r] : skips) {
      if (prev < l) {
        // cout << "query " << prev << " - " << l-1 << " = " << tree.query_max(0, 0, t, prev, l-1) << endl;
        ans[q.index] = max(ans[q.index], tree.query_max(0, 0, t, prev, l-1));
      }
      prev = max(prev, r+1);
    }
    if (prev <= t) {
      // cout << "query " << prev << " - " << t << " = " << tree.query_max(0, 0, t, prev, t) << endl;
      ans[q.index] = max(ans[q.index], tree.query_max(0, 0, t, prev, t));
    }
  };

  auto process_queries = [&](int node) {
    for (auto& q : query[node]) {
      process_query(q, node);
    }
  };

  function<void(int,int)> dfs2 = [&](int node, int parent) {
    process_queries(node);
    // cout << "node: " << node <<  ", query=" << tree.query_max(0, 0, t, t_in[node], t_out[node]) << endl;

    tree.update(0, 0, t, 1, t, 1);
    for (int next_node : adj[node]) if (next_node != parent) {
      tree.update(0, 0, t, t_in[next_node], t_out[next_node], -2);
      next[node] = next_node;
      dfs2(next_node, node);
      tree.update(0, 0, t, t_in[next_node], t_out[next_node], 2);
    }
    tree.update(0, 0, t, 1, t, -1);
  };

  dfs2(1, -1);

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
