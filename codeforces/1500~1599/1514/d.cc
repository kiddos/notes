#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 300000;
vector<vector<int>> indices(MAX_N + 1);

int query_count(int l, int r, int val) {
  return upper_bound(indices[val].begin(), indices[val].end(), r) -
         lower_bound(indices[val].begin(), indices[val].end(), l);
};

template <typename T, typename F>
class SegmentTreeImpl {
 public:
  SegmentTreeImpl(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
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
  pair<int, int> operator()(const pair<int, int>& p1,
                            const pair<int, int>& p2) {
    if (p1.first == p2.first) {
      return {p1.first, p1.second + p2.second};
    }
    if (p1.second >= p2.second) {
      return {p1.first, p1.second - p2.second};
    } else {
      return {p2.first, p2.second - p1.second};
    }
  }
};

using SegmentTree = SegmentTreeImpl<pair<int, int>, Merge>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
  }

  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i], 1});
  }
  SegmentTree tree(p);

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    --l;
    --r;
    int len = r - l + 1;

    pair<int, int> major = tree.query(l, r);
    int count = query_count(l, r, major.first);
    // cout << "major=" << major.first << ", count=" << count << endl;
    int ans = max(1, 2 * count - len);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
