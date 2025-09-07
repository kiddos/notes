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

using SegmentTree = GenericSegmentTree<i64, std::plus<i64>, 0, UpdateType::Add>;

void solve() {
  i64 n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;

  i64 row_total = (2 + (n + 1)) * n / 2;
  i64 total_count = row_total;
  for (int i = 1; i < n; ++i) {
    row_total += n;
    total_count += row_total;
  }

  vector<int> prefix_a(n);
  for (int i = 0, p = 0; i < n; ++i) {
    int ai = a[i] - '0';
    p += (ai == 0 ? 1 : -1);
    prefix_a[i] = p;
  }

  vector<int> prefix_b(n);
  for (int j = 0, p = 0; j < n; ++j) {
    int bj = b[j] - '0';
    p += (bj == 0 ? -1 : 1);
    prefix_b[j] = p;
  }

  const int offset = n;
  SegmentTree sum_tree(n * 2 + 1);
  SegmentTree count_tree(n * 2 + 1);
  for (int j = 0; j < n; ++j) {
    int idx = prefix_b[j] + offset;
    sum_tree.update(idx, prefix_b[j]);
    count_tree.update(idx, 1);
  }

  // cout << "total count=" << total_count << endl;

  i64 ans = total_count;
  for (int i = 0; i < n; ++i) {
    int idx = prefix_a[i] + n;
    i64 c1 = count_tree.query(0, idx);
    i64 part1 = prefix_a[i] * c1 - sum_tree.query(0, idx);
    i64 c2 = count_tree.query(idx+1, n * 2);
    i64 part2 = sum_tree.query(idx+1, n * 2) - c2 * prefix_a[i];
    // cout << "part1=" << part1 << ", part2=" << part2 << endl;
    ans -= (part1 + part2);
  }
  ans /= 2;
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
