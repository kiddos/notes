#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

template <typename T, typename F, T DEFAULT, UpdateType UPDATE_TYPE>
class GenericSegmentTree {
 public:
  GenericSegmentTree(int n) : n(n), data_(n * 4) {}

  T query(int i, int tl, int tr, int ql, int qr) noexcept {
    if (tr < ql || tl > qr) {
      return DEFAULT;
    }
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = (tl + tr) / 2;
    T left = query(i * 2 + 1, tl, tm, ql, qr);
    T right = query(i * 2 + 2, tm + 1, tr, ql, qr);
    return merge(left, right);
  }

  T query(int ql, int qr) noexcept { return query(0, 0, n - 1, ql, qr); }

  void update(int i, int tl, int tr, int index, const T& val) noexcept {
    if (tl == tr) {
      if constexpr (UPDATE_TYPE == UpdateType::Assign) {
        data_[i] = val;
      } else if constexpr (UPDATE_TYPE == UpdateType::Add) {
        data_[i] += val;
      }
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

  void update(int index, T val) noexcept { update(0, 0, n - 1, index, val); }

 private:
  int n;
  vector<T> data_;
  F f;

  inline T merge(T x, T y) { return f(x, y); }
};

template <typename T>
struct MinFunctor {
  T operator()(T a, T b) const { return std::min(a, b); }
};

using MinSegmentTree =
    GenericSegmentTree<int, MinFunctor<int>, numeric_limits<int>::max(),
                       UpdateType::Assign>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  MinSegmentTree tree(n);
  for (int i = 0; i < n; ++i) {
    tree.update(i, x[i]);
  }

  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int k = 0, u = 0;
      cin >> k >> u;
      k--;
      tree.update(k, u);
      x[i] = u;
    } else if (type == 2) {
      int a = 0, b = 0;
      cin >> a >> b;
      a--;
      b--;
      i64 result = tree.query(a, b);
      ans.push_back(result);
    }
  }

  for (i64 val : ans) {
    cout << val << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
