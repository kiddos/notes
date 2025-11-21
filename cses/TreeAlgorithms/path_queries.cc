#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

template <typename T, typename M, typename L, T IDENTITY>
class LazySegmentTree {
 public:
  LazySegmentTree(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
    lazy_ = vector<T>(max_size);
  }

  LazySegmentTree(vector<T>& data) {
    n = data.size();
    int x = ceil(log2(n)) + 1;
    int size = pow(2, x) - 1;
    data_ = vector<T>(size);
    lazy_ = vector<T>(size);

    build(data, 0, 0, n - 1);
  }

  void build(vector<T>& data, int i, int l, int r) {
    if (l > r) return;
    if (l == r) {
      data_[i] = data[l];
      return;
    }

    int m = l + (r - l) / 2;
    build(data, i * 2 + 1, l, m);
    build(data, i * 2 + 2, m + 1, r);
    data_[i] = M{}(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  void update(int i, int tl, int tr, int l, int r, T val) {
    push(i, tl, tr);

    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      L{}.apply_to_data_node(data_[i], tl, tr, val);
      if (tl != tr) {
        L{}.propagate(lazy_[i * 2 + 1], val);
        L{}.propagate(lazy_[i * 2 + 2], val);
      }
      lazy_[i] = 0;
      return;
    }

    int tm = (tl + tr) / 2;
    update(i * 2 + 1, tl, tm, l, r, val);
    update(i * 2 + 2, tm + 1, tr, l, r, val);
    data_[i] = M{}(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  void update(int l, int r, T val) { update(0, 0, n - 1, l, r, val); }

  T query(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);

    if (tr < ql || tl > qr) {
      return IDENTITY;
    }

    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = (tl + tr) / 2;
    T left = query(i * 2 + 1, tl, tm, ql, qr);
    T right = query(i * 2 + 2, tm + 1, tr, ql, qr);
    return M{}(left, right);
  }

  T query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }

 private:
  int n;
  vector<T> data_;
  vector<T> lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      L{}.apply_to_data_node(data_[i], tl, tr, lazy_[i]);
      if (tl != tr) {
        L{}.propagate(lazy_[i * 2 + 1], lazy_[i]);
        L{}.propagate(lazy_[i * 2 + 2], lazy_[i]);
      }
      lazy_[i] = 0;
    }
  }
};

struct SumMergePolicy {
  template <typename T>
  T operator()(const T& a, const T& b) const {
    return a + b;
  }
};

struct LazyAddPolicy {
  template <typename T>
  void apply_to_data_node(T& node_val, int tl, int tr,
                          const T& lazy_val) const {
    node_val += lazy_val * (tr - tl + 1);
  }

  template <typename T>
  void propagate(T& child_lazy_val, const T& parent_lazy_val) const {
    child_lazy_val += parent_lazy_val;
  }
};

using SegmentTree = LazySegmentTree<i64, SumMergePolicy, LazyAddPolicy, 0>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> v(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int t = 0;
  vector<int> t_in(n+1), t_out(n+1);
  vector<i64> initial_sum(n+1);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    t_in[node] = ++t;
    initial_sum[node] += v[node];
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      initial_sum[next_node] += initial_sum[node];
      self(self, next_node, node);
    }
    t_out[node] = t;
  };

  dfs(dfs, 1, 1);

  SegmentTree tree(t+1);
  for (int node = 1; node <= n; ++node) {
    tree.update(t_in[node], t_in[node], initial_sum[node]);
  }

  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int s = 0;
      i64 x = 0;
      cin >> s >> x;
      i64 diff = x - v[s];
      tree.update(t_in[s], t_out[s], diff);
      v[s] += diff;
    } else if (type == 2) {
      int s = 0;
      cin >> s;
      ans.push_back(tree.query(t_in[s], t_in[s]));
    }
  }

  for (i64 sum : ans) {
    cout << sum << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
