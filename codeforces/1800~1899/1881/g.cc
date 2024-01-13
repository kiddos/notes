#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(n * 4), lazy_(n * 4) {}

  void update(int i, int tl, int tr, int l, int r, int x) {
    if (tr < l || tl > r) {
      return;
    }

    push(i, tl, tr);

    if (tl >= l && tr <= r) {
      int len = tr - tl + 1;
      data_[i] += len * x;
      if (tl != tr) {
        lazy_[i*2+1] += x;
        lazy_[i*2+2] += x;
      }
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (l <= tm) update(i*2+1, tl, tm, l, r, x);
    if (r > tm) update(i*2+2, tm+1, tr, l, r, x);
    data_[i] = data_[i*2+1] + data_[i*2+2];
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (qr < tl || ql > tr) {
      return 0;
    }

    push(i, tl, tr);
    
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = tl + (tr - tl) / 2;
    return query(i*2+1, tl, tm, ql, min(qr, tm)) + query(i*2+2, tm+1, tr, max(ql, tm+1), qr);
  }

 private:
  vector<i64> data_, lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      int len = tr - tl + 1;
      data_[i] += len * lazy_[i];
      if (tl != tr) {
        lazy_[i*2+1] += lazy_[i];
        lazy_[i*2+2] += lazy_[i];
      }
      lazy_[i] = 0;
    }
  }
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;

  set<pair<int,int>> p;
  SegmentTree tree(n);
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    tree.update(0, 0, n-1, i, i, c);

    if (i > 0 && s[i] == s[i-1]) {
      p.insert({i-1, i});
    }
    if (i >= 2 && s[i] == s[i-2]) {
      p.insert({i-2, i});
    }
  }

  auto is_same = [&](int i1, int i2) -> bool {
    int c1 = tree.query(0, 0, n-1, i1, i1) % 26;
    int c2 = tree.query(0, 0, n-1, i2, i2) % 26;
    return c1 == c2;
  };

  auto update_palidrome = [&](int i1, int i2) {
    if (i2 < i1) {
      swap(i1, i2);
    }
    if (is_same(i1, i2)) {
      p.insert({i1, i2});
    } else {
      p.erase({i1, i2});
    }
  };

  for (int i = 0; i < m; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int l = 0, r = 0, x = 0;
      cin >> l >> r >> x;
      l--;
      r--;
      tree.update(0, 0, n-1, l, r, x % 26);

      if (l > 0) {
        update_palidrome(l-1, l);
        if (l+1 < n) {
          update_palidrome(l-1, l+1);
        }
      }
      if (l >= 2) {
        update_palidrome(l-2, l);
      }
      if (r+1 < n) {
        update_palidrome(r, r+1);
        if (r-1 >= 0) {
          update_palidrome(r-1, r+1);
        }
      }
      if (r+2 < n) {
        update_palidrome(r, r+2);
      }

      //for (int i = 0; i < n; ++i) {
        //cout << tree.query(0, 0, n-1, i, i) << " ";
      //}
      //cout << endl;
    } else if (type == 2) {
      int l = 0, r = 0;
      cin >> l >> r;
      l--;
      r--;
      auto it = p.lower_bound({l, 0});
      if (it != p.end() && it->second <= r) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
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
