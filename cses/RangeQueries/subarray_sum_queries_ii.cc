#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

struct Node {
  i64 sum;
  i64 max_sum;
  i64 prefix_max, suffix_max;

  constexpr Node(i64 x = 0)
      : sum(x), max_sum(max(0LL, x)), prefix_max(max(0LL, x)), suffix_max(max(0LL, x)) {}
  constexpr Node(i64 x, i64 max_sum, i64 p, i64 s)
      : sum(x), max_sum(max_sum), prefix_max(p), suffix_max(s) {}
};

struct Merge {
  Node operator()(const Node& lhs, const Node& rhs) {
    i64 merged_sum = lhs.sum + rhs.sum;
    i64 merged_max = max({lhs.suffix_max + rhs.prefix_max, lhs.max_sum, rhs.max_sum});
    i64 merged_prefix = max({lhs.prefix_max, lhs.sum + rhs.prefix_max});
    i64 merged_suffix = max({rhs.suffix_max, rhs.sum + lhs.suffix_max});
    return Node(merged_sum, merged_max, merged_prefix, merged_suffix);
  }
};

class SegmentTree {
 public:
  SegmentTree(int n) : n(n), data_(n * 4) {}

  Node query(int i, int tl, int tr, int ql, int qr) noexcept {
    if (tr < ql || tl > qr) {
      return Node(0);
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

  void update(int index, const Node& val) noexcept { update(0, 0, n - 1, index, val); }

 private:
  int n;
  vector<Node> data_;
  Merge f;

  inline Node merge(const Node& lhs, const Node& rhs) { return f(lhs, rhs); }
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> X(n);
  for (int i = 0; i < n; ++i) {
    cin >> X[i];
  }
  SegmentTree tree(n);
  for (int i = 0; i < n; ++i) {
    tree.update(i, Node(X[i]));
  }

  vector<i64> ans;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    Node result = tree.query(a, b);
    ans.push_back(result.max_sum);
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
