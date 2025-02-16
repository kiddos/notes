#include <bits/stdc++.h>

using namespace std;

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
      data_[i] = val;
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

using SegmentTree = SegmentTreeImpl<int, std::plus<int>>;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> data = {7, 2, 7, 2, 0};
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
  return 0;
}
