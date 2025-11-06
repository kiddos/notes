#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Node {
  i64 sum;
  i64 prefix_sum;

  constexpr Node(i64 x = 0) : sum(x), prefix_sum(x) {}
  constexpr Node(i64 x, i64 prefix_sum) : sum(x), prefix_sum(prefix_sum) {}
};

struct Merge {
  Node operator()(const Node& lhs, const Node& rhs) const {
    i64 sum = lhs.sum + rhs.sum;
    i64 p1 = lhs.sum + rhs.prefix_sum;
    i64 p2 = lhs.prefix_sum;
    return Node(sum, max(p1, p2));
  }
};

class SegmentTree {
 public:
  SegmentTree(int n) : n(n), data_(n * 4) {}

  Node query(int i, int tl, int tr, int ql, int qr) noexcept {
    if (tr < ql || tl > qr) {
      return Node();
    }
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = (tl + tr) / 2;
    Node left = query(i * 2 + 1, tl, tm, ql, qr);
    Node right = query(i * 2 + 2, tm + 1, tr, ql, qr);
    return merge(left, right);
  }

  Node query(int ql, int qr) noexcept { return query(0, 0, n - 1, ql, qr); }

  void update(int i, int tl, int tr, int index, const Node& val) noexcept {
    if (tl == tr) {
      data_[i] = val;
      return;
    }

    int tm = (tl + tr) / 2;
    if (index <= tm) {
      update(i * 2 + 1, tl, tm, index, val);
    } else {
      update(i * 2 + 2, tm + 1, tr, index, val);
    }
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  void update(int index, const Node& val) noexcept {
    update(0, 0, n - 1, index, val);
  }

 private:
  int n;
  vector<Node> data_;
  Merge f;

  inline Node merge(const Node& x, const Node& y) { return f(x, y); }
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  SegmentTree tree(n);
  for (int i = 0; i < n; ++i) {
    tree.update(i, Node(x[i]));
  }

  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int k = 0, u =0;
      cin >> k >> u;
      k--;
      tree.update(k, Node(u));
    } else if (type == 2) {
      int a = 0, b = 0;
      cin >> a >> b;
      a--;
      b--;
      Node result = tree.query(a, b);
      ans.push_back(max(result.prefix_sum, 0LL));
    }
  }

  for (i64 p : ans) {
    cout << p << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
