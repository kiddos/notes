#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

template <typename T, typename F>
class SegmentTreeImpl {
 public:
  SegmentTreeImpl(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
  }

  SegmentTreeImpl(vector<T>& data) {
    int n = data.size();
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
    build_tree(data, 0, 0, n-1);
  }

  void build_tree(vector<T>& data, int i, int tl, int tr) {
    if (tl == tr) {
      data_[i] = data[tl];
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build_tree(data, i * 2 + 1, tl, tm);
    build_tree(data, i * 2 + 2, tm + 1, tr);
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  T query(int i, int tl, int tr, int ql, int qr) {
    if (ql > qr) return T();
    if (tr < ql || tl > qr) return T();
    if (tl >= ql && tr <= qr) return data_[i];

    int tm = tl + (tr - tl) / 2;
    T left = query(i * 2 + 1, tl, tm, ql, min(tm, qr));
    T right = query(i * 2 + 2, tm + 1, tr, max(tm, ql), qr);
    return merge(left, right);
  }

  T query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }

  void update(int i, int tl, int tr, int index, const T& val) {
    if (tl == tr) {
      data_[i] += val;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (index <= tm) {
      update(i * 2 + 1, tl, tm, index, val);
    } else {
      update(i * 2 + 2, tm + 1, tr, index, val);
    }
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  void update(int index, T val) { update(0, 0, n - 1, index, val); }

 private:
  int n;
  vector<T> data_;

  inline T merge(T x, T y) { return F{}(x, y); }
};

using SegmentTree = SegmentTreeImpl<i64, std::plus<i64>>;

void solve() {
  int q = 0;
  cin >> q;
  vector<vector<int>> adj(2);
  vector<int> insert_time(2);
  vector<vector<pair<int,int>>> add_time(2);
  int size = 1;
  for (int i = 1; i <= q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int v = 0;
      cin >> v;
      size++;
      int u = size;
      adj[v].push_back(u);
      adj.push_back(vector<int>());
      insert_time.push_back(i);
      add_time.push_back(vector<pair<int,int>>());
    } else if (t == 2) {
      int v = 0, x = 0;
      cin >> v >> x;
      add_time[v].push_back({i, x});
    }
  }

  SegmentTree tree(q+1);
  vector<i64> ans(size+1);
  function<void(int)> dfs = [&](int node) {
    for (auto [t, x] : add_time[node]) {
      tree.update(t, x);
    }
    ans[node] = tree.query(insert_time[node], q);
    for (int next_node : adj[node]) {
      dfs(next_node);
    }
    for (auto [t, x] : add_time[node]) {
      tree.update(t, -x);
    }
  };

  dfs(1);

  for (int node = 1; node <= size; ++node) {
    cout << ans[node] << " ";
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
