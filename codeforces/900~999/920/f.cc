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

using SegmentTree = GenericSegmentTree<i64, std::plus<i64>, 0, UpdateType::Assign>;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (x != parent_[x]) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return;
    }
    parent_[px] = py;
  }

 private:
  vector<int> parent_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 max_a = *max_element(a.begin(), a.end());

  vector<int> divs(max_a+1, 1);
  for (int x = 2; x <= max_a; ++x) {
    for (int y = x; y <= max_a; y += x) {
      divs[y]++;
    }
  }

  SegmentTree tree(a);
  DisjointSet ds(n+1);

  for (int i = 0; i < m; ++i) {
    int t = 0, l = 0, r = 0;
    cin >> t >> l >> r;
    l--;
    r--;

    if (t == 1) {
      for (int j = ds.find(l); j <= r; j = ds.find(j+1)) {
        a[j] = divs[a[j]];
        tree.update(j, a[j]);
        if (a[j] <= 2) {
          ds.join(j, j+1);
        }
      }
    } else if (t == 2) {
      i64 sum = tree.query(l, r);
      cout << sum << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
