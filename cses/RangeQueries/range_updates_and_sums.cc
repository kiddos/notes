#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Node {
  i64 sum;
  i64 assign;
  i64 add;
  bool should_assign;
};

class LazySegmentTree {
 public:
  LazySegmentTree(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<Node>(max_size);
  }

  LazySegmentTree(vector<int>& data) {
    n = data.size();
    int x = ceil(log2(n)) + 1;
    int size = pow(2, x) - 1;
    data_ = vector<Node>(size);
    build(data, 0, 0, n - 1);
  }

  void build(vector<int>& data, int i, int l, int r) {
    if (l > r) return;
    if (l == r) {
      data_[i].sum = data[l];
      return;
    }

    int m = l + (r - l) / 2;
    build(data, i * 2 + 1, l, m);
    build(data, i * 2 + 2, m + 1, r);
    data_[i].sum = data_[i * 2 + 1].sum + data_[i * 2 + 2].sum;
  }

  void add(int i, int tl, int tr, int l, int r, i64 val) {
    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      data_[i].add += val;
      return;
    }
    push(i, tl, tr);

    int tm = (tl + tr) / 2;
    add(i * 2 + 1, tl, tm, l, r, val);
    add(i * 2 + 2, tm + 1, tr, l, r, val);
    push(i * 2 + 1, tl, tm);
    push(i * 2 + 2, tm + 1, tr);
    data_[i].sum = data_[i * 2 + 1].sum + data_[i * 2 + 2].sum;
  }

  void add(int l, int r, i64 val) { add(0, 0, n - 1, l, r, val); }

  void assign(int i, int tl, int tr, int l, int r, i64 val) {
    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      data_[i].assign = val;
      data_[i].should_assign = true;
      data_[i].add = 0;
      return;
    }
    push(i, tl, tr);

    int tm = (tl + tr) / 2;
    assign(i * 2 + 1, tl, tm, l, r, val);
    assign(i * 2 + 2, tm + 1, tr, l, r, val);
    push(i * 2 + 1, tl, tm);
    push(i * 2 + 2, tm + 1, tr);
    data_[i].sum = data_[i * 2 + 1].sum + data_[i * 2 + 2].sum;
  }

  void assign(int l, int r, i64 val) { assign(0, 0, n - 1, l, r, val); }

  i64 query(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);

    if (tr < ql || tl > qr) {
      return 0;
    }

    if (tl >= ql && tr <= qr) {
      return data_[i].sum;
    }

    int tm = (tl + tr) / 2;
    i64 left = query(i * 2 + 1, tl, tm, ql, qr);
    i64 right = query(i * 2 + 2, tm + 1, tr, ql, qr);
    return left + right;
  }

  i64 query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }

 private:
  int n;
  vector<Node> data_;
  vector<Node> lazy_;

  void propagate(int i, int j) {
    if (data_[i].should_assign) {
      data_[j].should_assign = true;
      data_[j].assign = data_[i].assign;
      data_[j].add = data_[i].add;
    } else {
      data_[j].add += data_[i].add;
    }
  }

  void push(int i, int tl, int tr) {
    int len = tr - tl + 1;
    if (data_[i].should_assign) {
      data_[i].sum = data_[i].assign * len;
    }
    data_[i].sum += data_[i].add * len;

    if (tl != tr) {
      propagate(i, i * 2 + 1);
      propagate(i, i * 2 + 2);
    }

    data_[i].add = 0;
    data_[i].should_assign = false;
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

struct LazyAssignPolicy {
  template <typename T>
  void apply_to_data_node(T& node_val, int tl, int tr,
                          const T& lazy_val) const {
    node_val = lazy_val * (tr - tl + 1);
  }

  template <typename T>
  void propagate(T& child_lazy_val, const T& parent_lazy_val) const {
    child_lazy_val = parent_lazy_val;
  }
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  LazySegmentTree tree(t);
  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int a = 0, b = 0, x = 0;
      cin >> a >> b >> x;
      a--;
      b--;
      tree.add(a, b, x);
    } else if (type == 2) {
      int a = 0, b = 0, x = 0;
      cin >> a >> b >> x;
      a--;
      b--;
      tree.assign(a, b, x);
    } else if (type == 3) {
      int a = 0, b = 0;
      cin >> a >> b;
      a--;
      b--;
      ans.push_back(tree.query(a, b));
    }
    // for (int j = 0; j < n; ++j) {
    //   cout << tree.query(j, j) << " ";
    // }
    // cout << endl;
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
