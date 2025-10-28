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

using SegmentTree = GenericSegmentTree<int, std::plus<int>, 0, UpdateType::Add>;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  if (k == 0) {
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for (int i : ans) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }

  SegmentTree tree(n);
  for (int i = 0; i < n; ++i) {
    tree.update(i, 1);
  }

  auto skip = [&](int idx) -> int {
    int total = tree.query(0, n-1);
    int move = k % total;
    if (move == 0) {
      return idx;
    }

    // cout << "idx=" << idx << endl;
    // for (int i = 0; i < n; ++i) {
    //   cout << tree.query(i, i) << " ";
    // }
    // cout << endl;

    int right_sum = tree.query(idx, n-1);
    if (right_sum >= move) {
      int l = idx, r = n-1;
      int result = r;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int sum = tree.query(idx, mid);
        if (sum >= move) {
          result = mid;
          r = mid -1;
        } else {
          l = mid +1;
        }
      }
      return result;
    } else {
      int x = move-right_sum;
      int l = 0, r = idx-1;
      int result = r;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int sum = tree.query(0, mid);
        if (sum >= x) {
          result = mid;
          r = mid -1;
        } else {
          l = mid +1;
        }
      }
      return result;
    }
  };

  auto next_one = [&](int idx) -> int {
    int right_sum = tree.query(idx, n-1);
    if (right_sum > 0) {
      int l = idx, r = n-1;
      int result = r;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int sum = tree.query(idx, mid);
        if (sum > 0) {
          result = mid;
          r = mid -1;
        } else {
          l = mid +1;
        }
      }
      return result;
    } else {
      int l = 0, r = idx-1;
      int result = r;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int sum = tree.query(0, mid);
        if (sum > 0) {
          result = mid;
          r = mid -1;
        } else {
          l = mid +1;
        }
      }
      return result;
    }
  };

  int idx = 0;
  for (int i = 0; i < n; ++i) {
    int idx2 = skip(idx);
    idx2 = next_one((idx2+1) % n);

    tree.update(idx2, -1);
    cout << idx2+1 << " ";
    idx = idx2;

    // for (int j = 0; j < n; ++j) {
    //   cout << tree.query(j, j) << " ";
    // }
    // cout << endl;
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
