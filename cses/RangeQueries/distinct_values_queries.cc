#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

template <typename T, typename F, T DEFAULT, UpdateType UPDATE_TYPE>
class GenericSegmentTree {
 public:
  GenericSegmentTree(int n) : n(n), data_(n * 4) {}

  GenericSegmentTree(vector<T>& data) : n(data.size()), data_(data.size() * 4) {
    build_tree(data, 0, 0, n - 1);
  }

  void build_tree(vector<T>& data, int i, int tl, int tr) noexcept {
    if (tl == tr) {
      data_[i] = data[tl];
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build_tree(data, i * 2 + 1, tl, tm);
    build_tree(data, i * 2 + 2, tm + 1, tr);
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

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

template <typename T>
struct MaxFunctor {
  T operator()(T a, T b) const { return std::max(a, b); }
};

using SegmentTree = GenericSegmentTree<int, std::plus<int>, 0, UpdateType::Add>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<pair<int,int>> queries;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    queries.emplace_back(a, b);
  }
  vector<vector<pair<int,int>>> endings(n);
  for (int i = 0; i < q; ++i) {
    auto [a, b] = queries[i];
    endings[b].push_back({a, i});
  }
  SegmentTree tree(n);
  map<int,int> last_index;
  vector<int> ans(q);
  for (int i = 0; i < n; ++i) {
    if (last_index.count(x[i])) {
      int idx = last_index[x[i]];
      tree.update(idx, -1);
    }
    last_index[x[i]] = i;
    tree.update(i, 1);

    for (auto [start, query_idx] : endings[i]) {
      ans[query_idx] = tree.query(start, i);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
