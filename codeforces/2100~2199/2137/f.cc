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
struct MaxFunctor {
  T operator()(T a, T b) const { return std::max(a, b); }
};

using SegmentTree = GenericSegmentTree<int, MaxFunctor<int>, 0, UpdateType::Assign>;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  SegmentTree tree_a(n);
  for (int i = 0; i < n; ++i) {
    tree_a.update(i, a[i]);
  }

  i64 ans = 0;
  for (int i = 1; i < n; ++i) {
    int l = 0, r = i-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (tree_a.query(mid, i-1) >= max(a[i], b[i])) {
        idx = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    i64 left_count = idx+1;
    i64 right_count = n-i;
    // cout << left_count <<"," << right_count << endl;
    ans += left_count * right_count;
  }

  // count subarray with a[i] == b[i]
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      int l = 0, r = i-1;
      int idx = -1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        if (tree_a.query(mid, i-1) < a[i]) {
          idx = mid;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }

      i64 right_count = n-i;
      i64 left_count = idx >= 0 ? i-idx+1 : 1;
      ans += right_count * left_count;
    }
  }

  cout << ans << endl;

  // int ans2 = 0;
  // for (int l = 0; l < n; ++l) {
  //   int p = 0;
  //   int count = 0;
  //   for (int r = l; r < n; ++r) {
  //     if (a[r] <= p) {
  //       if (b[r] <= p) {
  //         count++;
  //       }
  //     } else {
  //       if (a[r] == b[r]) {
  //         count++;
  //       }
  //     }
  //     p = max(p, a[r]);
  //
  //     // cout << count << " ";
  //     ans2 += count;
  //   }
  //   // cout << endl;
  // }
  // cout << ans2 << endl;
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
