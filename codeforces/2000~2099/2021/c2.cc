#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : n(n), min_val_(n * 4), max_val_(n * 4), count_(n * 4) {
  }

  void update(int i, int tl, int tr, int idx, int x) {
    if (tl > tr) {
      return;
    }

    if (tl == tr) {
      min_val_[i] = x;
      max_val_[i] = x;
      count_[i] = 1;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (idx <= tm) {
      update(i * 2 + 1, tl, tm, idx, x);
    } else {
      update(i * 2 + 2, tm + 1, tr, idx, x);
    }
    merge(i);
  }

  void update(int idx, int x) {
    update(0, 0, n-1, idx, x);
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) {
      return 0;
    }
    if (tl >= ql && tr <= qr) {
      return count_[i];
    }
    int tm = tl + (tr - tl) / 2;
    int left = query(i * 2 + 1, tl, tm, ql, min(tm, qr));
    int right = query(i * 2 + 2, tm + 1, tr, max(tm+1, ql), qr);
    return left + right;
  }

  int query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  int query_min(int i, int tl, int tr, int ql, int qr) {
    if (tl > qr || tr < ql) {
      return numeric_limits<int>::max();
    }
    if (tl >= ql && tr <= qr) {
      return min_val_[i];
    }
    int tm = tl + (tr - tl) / 2;
    int left = query_min(i * 2 + 1, tl, tm, ql, min(tm, qr));
    int right = query_min(i * 2 + 2, tm + 1, tr, max(tm+1, ql), qr);
    return min(left, right);
  }

  int query_min(int l, int r) {
    return query_min(0, 0, n-1, l, r);
  }

 private:
  int n;
  vector<int> min_val_, max_val_, count_;

  void merge(int i) {
    if (min_val_[i * 2 + 2] >= max_val_[i * 2 + 1]) {
      count_[i] = count_[i * 2 + 1] + count_[i * 2 + 2];
    } else {
      count_[i] = 0;
    }
    min_val_[i] = min(min_val_[i * 2 + 1], min_val_[i * 2 + 2]);
    max_val_[i] = max(max_val_[i * 2 + 1], max_val_[i * 2 + 2]);
  }
};

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<int> a2i(n+1);
  for (int i = 0; i < n; ++i) {
    a2i[a[i]] = i;
  }

  vector<set<int>> indices(n+1);
  for (int i = 0; i < m; ++i) {
    int order = a2i[b[i]];
    indices[order].insert(i);
  }

  SegmentTree tree(n);

  for (int i = 0; i < n; ++i) {
    if (indices[i].empty()) {
      // cout << i << "=" << m << endl;
      tree.update(i, m);
    } else {
      // cout << i << "=" << *indices[i].begin() << endl;
      tree.update(i, *indices[i].begin());
    }
  }

  auto update = [&](int s, int t) {
    if (b[s] == t) {
      return;
    }
    
    // remove
    int order = a2i[b[s]];
    indices[order].erase(s);
    if (indices[order].empty()) {
      tree.update(order, m);
    } else {
      tree.update(order, *indices[order].begin());
    }

    b[s] = t;
    order = a2i[b[s]];
    indices[order].insert(s);
    tree.update(order, *indices[order].begin());
  };

  auto do_query = [&]() {
    // for (int i = 0; i < n; ++i) {
    //   cout << "first occurence of " << a[i] << " at " << tree.query_min(i, i) << endl;
    // }

    int increasing_count = tree.query(0, n-1);
    if (increasing_count == n) {
      cout << "YA" << endl;
    } else {
      cout << "TIDAK" << endl;
    }
  };

  do_query();
  for (int i = 0; i < q; ++i) {
    int s = 0, t = 0;
    cin >> s >> t;
    s--;
    update(s, t);
    do_query();
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
