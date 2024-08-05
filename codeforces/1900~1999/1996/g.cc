#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int INF = numeric_limits<int>::max();

struct Node {
  int min_val;
  int min_sum;
};

class SegmentTree {
 public:
  SegmentTree(int n) : nodes_(n * 4), lazy_(4 * n) {
    function<void(int,int,int)> build = [&](int i, int tl, int tr) {
      if (tl == tr) {
        nodes_[i] = Node{0, 1};
        return;
      }
      if (tl > tr) {
        return;
      }

      int tm = tl + (tr - tl) / 2;
      build(i * 2 + 1, tl, tm);
      build(i * 2 + 2, tm + 1, tr);
      nodes_[i] = merge_nodes(nodes_[i * 2 + 1], nodes_[i * 2 + 2]);
    };
    build(0, 0, n-1);
  }

  void update(int i, int tl, int tr, int l, int r, int x) {
    push(i, tl, tr);

    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      nodes_[i].min_val += x;

      if (tl != tr) {
        lazy_[i * 2 + 1] += x;
        lazy_[i * 2 + 2] += x;
      }
      return;
    }

    int tm = tl + (tr - tl) / 2;
    update(i * 2 + 1, tl, tm, l, min(r, tm), x);
    update(i * 2 + 2, tm + 1, tr, max(l, tm+1), r, x);
    nodes_[i] = merge_nodes(nodes_[i * 2 + 1], nodes_[i * 2 + 2]);
  }

  Node query(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);

    if (tl >= ql && tr <= qr) {
      return nodes_[i];
    }
    if (tl > qr || tr < ql) {
      return Node{INF, 0};
    }

    int tm = tl + (tr - tl) / 2;
    auto left = query(i * 2 + 1, tl, tm, ql, min(qr, tm));
    auto right = query(i * 2 + 2, tm + 1, tr, max(ql, tm + 1), qr);
    return merge_nodes(left, right);
  }

 private:
  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      nodes_[i].min_val += lazy_[i];

      if (tl != tr) {
        lazy_[i * 2 + 1] += lazy_[i];
        lazy_[i * 2 + 2] += lazy_[i];
      }
      lazy_[i] = 0;
    }
  }

  Node merge_nodes(const Node& left, const Node& right) {
    if (left.min_val < right.min_val) {
      return left;
    } else if (right.min_val < left.min_val) {
      return right;
    } else {
      return Node{left.min_val, left.min_sum + right.min_sum};
    }
  }

  vector<Node> nodes_;
  vector<int> lazy_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  SegmentTree tree(n);
  // we have edges 0 ~ n-1
  // edge 0 connects n to 1
  // starts by not using edge 0
  for (auto& [a, b] : edges) {
    tree.update(0, 0, n-1, a, b-1, 1);
  }

  vector<vector<int>> edge_starts(n + 1);
  vector<vector<int>> edge_ends(n + 1);
  for (int i = 0; i < m; ++i) {
    auto [a, b] = edges[i];
    edge_starts[a].push_back(i);
    edge_ends[b].push_back(i);
  }

  auto result = tree.query(0, 0, n-1, 0, n-1);
  int ans = n - result.min_sum;
  for (int edge = 1; edge <= n; ++edge) {
    // not do not use edge e
    // update all path using edge e to use the other configuration
    for (int p : edge_starts[edge]) {
      auto [a, b] = edges[p];
      tree.update(0, 0, n-1, a, b-1, -1);
      tree.update(0, 0, n-1, 0, a-1, 1);
      tree.update(0, 0, n-1, b, n-1, 1);
    }
    for (int p : edge_ends[edge]) {
      auto [a, b] = edges[p];
      tree.update(0, 0, n-1, 0, a-1, -1);
      tree.update(0, 0, n-1, b, n-1, -1);
      tree.update(0, 0, n-1, a, b-1, 1);
    }

    auto result = tree.query(0, 0, n-1, 0, n-1);
    ans = min(ans, n - result.min_sum);
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
