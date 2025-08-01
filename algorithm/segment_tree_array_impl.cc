#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

template <typename T, typename F, T DEFAULT, UpdateType UPDATE_TYPE>
class GenericSegmentTree {
 public:
  GenericSegmentTree(int n) : n(n) {
    int x = (int)(ceil(log2(n + 1)));
    int max_size = 2 * (int)pow(2, x);
    data_ = vector<T>(max_size);
  }

  GenericSegmentTree(vector<T>& data) {
    n = data.size();
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
    build_tree(data, 0, 0, n - 1);
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
    if (ql > qr) return DEFAULT;
    if (tr < ql || tl > qr) return DEFAULT;
    if (tl >= ql && tr <= qr) return data_[i];

    int tm = tl + (tr - tl) / 2;
    T left = query(i * 2 + 1, tl, tm, ql, min(tm, qr));
    T right = query(i * 2 + 2, tm + 1, tr, max(tm, ql), qr);
    return merge(left, right);
  }

  T query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }

  void update(int i, int tl, int tr, int index, const T& val) {
    if (tl == tr) {
      if constexpr (UPDATE_TYPE == UpdateType::Assign) {
        data_[i] = val;
      } else if constexpr (UPDATE_TYPE == UpdateType::Add) {
        data_[i] += val;
      }
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

template <typename T>
struct MinFunctor {
  T operator()(T a, T b) const { return std::min(a, b); }
};

template <typename T>
struct MaxFunctor {
  T operator()(T a, T b) const { return std::max(a, b); }
};

using MinSegmentTree =
    GenericSegmentTree<i64, MinFunctor<i64>, numeric_limits<i64>::max(),
                       UpdateType::Assign>;
using MaxSegmentTree =
    GenericSegmentTree<i64, MaxFunctor<i64>, numeric_limits<i64>::min(),
                       UpdateType::Assign>;
using SegmentTree = GenericSegmentTree<i64, std::plus<i64>, 0, UpdateType::Add>;

struct Node {
  i64 sum;
  i64 prefix_sum, suffix_sum;
  i64 max_val;

  constexpr Node(i64 x = 0)
      : sum(x), prefix_sum(x), suffix_sum(x), max_val(x) {}
  constexpr Node(i64 x, i64 p, i64 s, i64 m)
      : sum(x), prefix_sum(p), suffix_sum(s), max_val(m) {}
};

struct Merge {
  Node operator()(const Node& lhs, const Node& rhs) {
    i64 total = lhs.sum + rhs.sum;
    i64 prefix = max(lhs.prefix_sum, lhs.sum + rhs.prefix_sum);
    i64 suffix = max(rhs.suffix_sum, rhs.sum + lhs.suffix_sum);
    i64 max_val = max({lhs.suffix_sum + rhs.prefix_sum, lhs.max_val, rhs.max_val});
    return Node(total, prefix, suffix, max_val);
  }
};

constexpr Node NODE_DEFAULT(0, -1e9, -1e9, numeric_limits<i64>::min());
using NodeSegmentTree =
    GenericSegmentTree<Node, Merge, NODE_DEFAULT, UpdateType::Assign>;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<i64> data = {7, 2, 7, 2, 0};
  SegmentTree tree(data);
  const int n = data.size();
  tree.update(0, 0, n - 1, 4, 6);
  tree.update(0, 0, n - 1, 0, 2);
  tree.update(0, 0, n - 1, 0, 9);
  assert(tree.query(0, 0, n - 1, 4, 4) == 6);
  tree.update(0, 0, n - 1, 3, 8);
  assert(tree.query(0, 0, n - 1, 0, 4) == 32);
  tree.update(0, 0, n - 1, 4, 1);
  assert(tree.query(0, 0, n - 1, 0, 3) == 26);
  assert(tree.query(0, 0, n - 1, 0, 4) == 27);
  tree.update(0, 0, n - 1, 0, 4);

  NodeSegmentTree tree2(n);
  return 0;
}
