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

using MaxSegmentTree = GenericSegmentTree<int, MaxFunctor<int>, numeric_limits<int>::min(), UpdateType::Assign>;

template <typename T>
struct MinFunctor {
  T operator()(T a, T b) const { return std::min(a, b); }
};

using MinSegmentTree = GenericSegmentTree<int, MinFunctor<int>, numeric_limits<int>::max(), UpdateType::Assign>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> queries;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    queries.emplace_back(l, r);
  }

  vector<int> next_smaller(n, -1);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.back()] > a[i]) {
      next_smaller[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  st.clear();
  vector<int> prev_greater(n, -1);
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && a[st.back()] < a[i]) {
      prev_greater[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  vector<int> after(n, -1);
  vector<int> before(n, -1);
  for (int i = 0; i < n; ++i) {
    int left = prev_greater[i];
    int right = next_smaller[i];
    if (left >= 0 && right >= 0) {
      after[left] = right;
      before[right] = left;
    }
  }

  MinSegmentTree index_min(n);
  MaxSegmentTree index_max(n);
  for (int i = 0; i < n; ++i) {
    if (after[i] >= 0) {
      index_min.update(i, after[i]);
    } else {
      index_min.update(i, numeric_limits<int>::max());
    }
    if (before[i] >= 0) {
      index_max.update(i, before[i]);
    } else {
      index_max.update(i, numeric_limits<int>::min());
    }
  }

  auto perform_query = [&](int l, int r) -> bool {
    int right_bound = index_min.query(l, r);
    int left_bound = index_max.query(l, r);
    if (right_bound <= r || left_bound >= l) {
      return false;
    }
    return true;
  };

  vector<bool> ans;
  for (int i = 0; i < q; ++i) {
    auto [l, r] = queries[i];
    ans.push_back(perform_query(l, r));
  }
  for (int i = 0; i < q; ++i) {
    if (ans[i]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
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
