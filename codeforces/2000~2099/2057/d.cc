#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_A = 1e9;

struct Value {
  i64 min1, max1;
  i64 min2, max2;
  i64 case1, case2;

  Value() : min1(MAX_A), max1(0), min2(MAX_A), max2(0), case1(0), case2(0) {}
  Value(i64 x1, i64 x2)
      : min1(x1), max1(x1), min2(x2), max2(x2), case1(0), case2(0) {}
};

template <typename T, typename F>
class SegmentTreeImpl {
 public:
  SegmentTreeImpl(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
  }

  void build_tree(vector<T>& nums, int i, int tl, int tr) {
    if (tl == tr) {
      data_[i] = nums[tl];
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build_tree(nums, i * 2 + 1, tl, tm);
    build_tree(nums, i * 2 + 2, tm + 1, tr);
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

struct Merge {
  Value operator()(const Value& lhs, const Value& rhs) const {
    Value v;
    v.min1 = min(lhs.min1, rhs.min1);
    v.max1 = max(lhs.max1, rhs.max1);
    v.min2 = min(lhs.min2, rhs.min2);
    v.max2 = max(lhs.max2, rhs.max2);
    v.case1 = max({lhs.case1, rhs.case1, rhs.max1 - lhs.min1});
    v.case2 = max({lhs.case2, rhs.case2, lhs.max2 - rhs.min2});
    return v;
  }
};

using SegmentTree = SegmentTreeImpl<Value, Merge>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
  }

  SegmentTree tree(n + 1);
  vector<Value> values(n + 1);
  for (int i = 1; i <= n; ++i) {
    i64 x1 = a[i] - i, x2 = a[i] + i;
    values[i] = Value(x1, x2);
    tree.update(i, values[i]);
  }

  auto query_answer = [&]() -> i64 {
    const Value v = tree.query(1, n);
    return max(v.case1, v.case2);
  };

  vector<i64> ans = {query_answer()};
  for (int i = 0; i < q; ++i) {
    int p = 0, x = 0;
    cin >> p >> x;
    a[p] = x;
    values[p] = Value(x - p, x + p);
    tree.update(p, values[p]);
    ans.push_back(query_answer());
  }

  for (i64 x : ans) {
    cout << x << endl;
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
