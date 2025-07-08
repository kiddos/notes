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

using SegmentTree = SegmentTreeImpl<i64, std::plus<i64>, 0>;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  s = " " + s;

  int m = n * 2;
  SegmentTree b_sum(m + 1), count(m + 1);
  count.update(n, 1);

  i64 ans = 0;
  for (int i = 1, b = 0; i <= n; ++i) {
    if (s[i] == '1') {
      b++;
    } else {
      b--;
    }

    if (s[i] == '1') {
      i64 total_b = b * count.query(0, n + b) - b_sum.query(0, n + b) + 
        b_sum.query(n + b + 1, m) - b * count.query(n + b + 1, m);
      i64 total_len = (i64)(i + 1) * i / 2;
      ans += (total_b + total_len) / 2;
      // cout << "idx=" << i << ",b=" << b << ",total_b=" << total_b << ", total_length=" << total_len << ",ans=" << ans << endl;
    }
    b_sum.update(b + n, b);
    count.update(b + n, 1);
  }

  b_sum = SegmentTree(m + 1);
  count = SegmentTree(m + 1);
  count.update(n, 1);
  for (int i = 1, b = 0; i <= n; ++i) {
    if (s[i] == '0') {
      b++;
    } else {
      b--;
    }

    if (s[i] == '0') {
      i64 total_b = b * count.query(0, n + b) - b_sum.query(0, n + b) + 
        b_sum.query(n + b + 1, m) - b * count.query(n + b + 1, m);
      i64 total_len = (i64)(i + 1) * i / 2;
      ans += (total_b + total_len) / 2;
    }
    b_sum.update(b + n, b);
    count.update(b + n, 1);
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
