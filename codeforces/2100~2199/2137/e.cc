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

using SegmentTree = GenericSegmentTree<int, std::plus<int>, 0, UpdateType::Assign>;

vector<int> mex(vector<int>& a) {
  int n = a.size();
  SegmentTree tree(n);
  vector<int> count(n+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  for (int i = 0; i <= n; ++i) {
    if (count[i]) {
      tree.update(i, 1);
    }
  }

  auto query_mex = [&]() -> int {
    int l = 0, r = n;
    int m = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int count = tree.query(0, mid);
      if (count < mid+1) {
        m = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return m;
  };

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    count[a[i]]--;
    if (count[a[i]] == 0) {
      tree.update(a[i], 0);
    }
    b[i] = query_mex();
    count[a[i]]++;
    tree.update(a[i], 1);
  }
  return b;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b = a;
  vector<vector<int>> history;
  for (int j = 0; j < 3 && k > 0; ++j, --k) {
    b = mex(b);
    // for (int i = 0; i < n; ++i) {
    //   cout << b[i] << " ";
    // }
    // cout << endl;
    history.push_back(b);
  }

  i64 ans = 0;
  if (k % 2 == 0) {
    vector<int>& b0 = history.back();
    ans = accumulate(b0.begin(), b0.end(), 0LL);
  } else {
    vector<int>& b0 = history[history.size()-2];
    ans = accumulate(b0.begin(), b0.end(), 0LL);
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
