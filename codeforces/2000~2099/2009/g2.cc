#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(n * 4), lazy_(n * 4, -1) {}

  void update(int i, int tl, int tr, int l, int r, i64 x) {
    push(i, tl, tr);

    if (tl >= l && tr <= r) {
      data_[i] = (tr - tl + 1) * x;
      if (tl != tr) {
        lazy_[i * 2 + 1] = x;
        lazy_[i * 2 + 2] = x;
      }
      return;
    }

    if (tl > r || tr < l) {
      return;
    }

    int tm = tl + (tr - tl) / 2;
    update(i * 2 + 1, tl, tm, l, r, x);
    update(i * 2 + 2, tm + 1, tr, l, r, x);
    data_[i] = data_[i * 2 + 1] + data_[i * 2 + 2];
  }

  i64 query(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);

    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    if (tl > qr || tr < ql) {
      return 0;
    }
    int tm = tl + (tr - tl) / 2;
    i64 left = query(i * 2 + 1, tl, tm, ql, min(qr, tm));
    i64 right = query(i * 2 + 2, tm + 1, tr, max(ql, tm+1), qr);
    return left + right;
  }

 private:
  void push(int i, int tl, int tr) {
    if (lazy_[i] >= 0) {
      data_[i] = (tr - tl + 1) * lazy_[i];
      if (tl != tr) {
        lazy_[i * 2 + 1] = lazy_[i];
        lazy_[i * 2 + 2] = lazy_[i];
      }
      lazy_[i] = -1;
    }
  }

  vector<i64> data_, lazy_;
};

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<array<int, 3>> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i][0] >> queries[i][1];
    queries[i][2] = i;
  }

  vector<i64> d(n+1);
  for (int i = 1; i <= n; ++i) {
    d[i] = a[i] - i;
  }

  map<int, int> d_count;
  set<pair<int,int>> s;

  auto add = [&](int x) {
    s.erase({d_count[x], x});
    d_count[x]++;
    s.insert({d_count[x], x});
  };

  auto remove = [&](int x) {
    s.erase({d_count[x], x});
    d_count[x]--;
    s.insert({d_count[x], x});
  };
  
  vector<i64> c(n+1);
  for (int i = 1; i <= n; ++i) {
    add(d[i]);
    if (i > k) {
      remove(d[i - k]);
    }
    if (i >= k) {
      c[i-k+1] = k - s.rbegin()->first;
    }
  }

  // cout << "c:" << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << c[i] << " ";
  // }
  // cout << endl;

  sort(queries.begin(), queries.end(), [&](auto& q1, auto& q2) {
    if (q1[0] == q2[0]) {
      return q1[1] < q2[1];
    }
    return q1[0] > q2[0];
  });

  SegmentTree tree(n+1);

  auto find_last = [&](int start, int x) -> int {
    int l = start+1, r = n-k+1;
    int ans = start;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      i64 val = tree.query(0, 0, n+1, mid, mid);
      if (val > x) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  };

  tree.update(0, 0, n+1, n-k+1, n-k+1, c[n-k+1]);
  // cout << "first tree:" << endl;
  // for (int i = 0; i <= n; ++i) {
  //   cout << tree.query(0, 0, n+1, i, i) << " ";
  // }
  // cout << endl;

  vector<i64> ans(q);
  for (int i = 0, x = n - k + 1; i < q; ++i) {
    auto [l, r, idx] = queries[i];
    while (x > l) {
      x--;
      int last = find_last(x, c[x]);
      // cout << "x=" << x << "c=" << c[x] << ",last=" << last << endl;
      tree.update(0, 0, n+1, x, last, c[x]);
    }
    // cout << "process query: " << idx << " ";
    // cout << "tree:" << endl;
    // for (int i = 0; i <= n; ++i) {
    //   cout << tree.query(0, 0, n+1, i, i) << " ";
    // }
    // cout << endl;
    ans[idx] = tree.query(0, 0, n+1, l, r-k+1);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
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
