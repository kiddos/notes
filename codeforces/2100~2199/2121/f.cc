#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

template <typename T, typename F, T DEFAULT>
class SegmentTreeImpl {
 public:
  SegmentTreeImpl(int n) : n(n) {
    int x = (int)(ceil(log2(n+1)));
    int max_size = 2 * (int)pow(2, x);
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

template <typename T>
struct MaxFunctor {
  T operator()(T a, T b) const { return std::max(a, b); }
};

using SegmentTree =
    SegmentTreeImpl<i64, MaxFunctor<i64>, numeric_limits<i64>::min()>;

void solve() {
  int n = 0;
  i64 s = 0;
  i64 x = 0;
  cin >> n >> s >> x;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  SegmentTree tree(a);

  map<i64, vector<int>> indices;
  indices[0].push_back(0);

  i64 p = 0;
  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    p += a[i];
    vector<int>& idx = indices[p - s];
    int size = idx.size();
    int l = 0, r = size-1;
    int i1 = -1, i2 = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (tree.query(idx[mid]+1, i) >= x) {
        i1 = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }

    l = 0, r = size-1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (tree.query(idx[mid]+1, i) <= x) {
        i2 = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }

    if (i1 >= 0 && i2 >= 0) {
      // cout << "range=" << idx[i1] << "," << idx[i2] << endl;
      i64 max_val = tree.query(idx[i1]+1, i);
      if (max_val == x) {
        int len = i1 - i2 + 1;
        ans += len;
      }
    }

    indices[p].push_back(i);
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
