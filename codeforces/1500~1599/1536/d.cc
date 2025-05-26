#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

template <typename T, typename F, T DEFAULT>
class SegmentTreeImpl {
 public:
  SegmentTreeImpl(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
  }

  SegmentTreeImpl(vector<T>& data) {
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

template <typename T>
struct MinFunctor {
  T operator()(T a, T b) const { return std::min(a, b); }
};

template <typename T>
struct MaxFunctor {
  T operator()(T a, T b) const { return std::max(a, b); }
};

using SegmentTree = SegmentTreeImpl<i64, std::plus<i64>, 0>;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  // given the question b[i] is the median
  // when transition from b[i] -> b[i+1]
  // b[i+1] becomes the median,
  // if there is a b[j] that is min(b[i], b[i+1]) < b[j] < max(b[i], b[i+1])
  // the median will be b[j] instead of b[i+1]

  set<int> s;
  for (int i = 0; i < n; ++i) {
    s.insert(b[i]);
    s.insert(b[i]-1);
    s.insert(b[i]+1);
  }
  map<int,int> ids;
  int id = 0;
  for (int x : s) {
    ids[x] = id++;
  }

  int m = ids.size();
  SegmentTree tree(m);
  tree.update(ids[b[0]], 1);
  for (int i = 1; i < n; ++i) {
    int min_val = min(b[i-1], b[i]);
    int max_val = max(b[i-1], b[i]);
    int result = tree.query(ids[min_val+1], ids[max_val-1]);
    if (result > 0) {
      cout << "NO" << endl;
      return;
    }
    tree.update(ids[b[i]], 1);
  }

  cout << "YES" << endl;
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
