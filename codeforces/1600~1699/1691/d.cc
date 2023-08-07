#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;

// the math is as follow:
// 
// assume a[i] is the max at some interval [l, r]
// so we just need to find
//
// a[l] + a[l+1] + ... + a[i] + ... + a[r-1] + a[r] > a[i]
// => a[l] + a[l+1] + ... + a[i-1] + a[i+1] + ... + a[r-1] + a[r] > 0
// so need to find
// a[l] + a[l+1] + ... + a[i-1] > 0
// or a[i+1] + ... + a[r-1] + a[r] > 0
//
// so the trick I learn here is to use segment tree
// for the prefix part, to get the largest possible (a[l] + a[l+1] + ... + a[i-1])
// we just need to compute prefix_sum[i-1] - min(prefix_sum[j] for j in l...i-1)
//
// for the suffix part, we can do this in a similar way
// to find the largest possible (a[i+1] + ... + a[r-1] + a[r])
// compute max(prefix_sum[j] for j in i+1...r) - prefix_sum[i]

class SegmentTree {
 public:
  SegmentTree(vector<i64>& p) : min_vals_(4 * p.size()), max_vals_(4 * p.size()) {

    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l > r) return;
      if (l == r) {
        max_vals_[i] = p[l];
        min_vals_[i] = p[l];
        return;
      }
      int m = l + (r-l) / 2;
      build(i*2+1, l, m);
      build(i*2+2, m+1, r);

      max_vals_[i] = max(max_vals_[i*2+1], max_vals_[i*2+2]);
      min_vals_[i] = min(min_vals_[i*2+1], min_vals_[i*2+2]);
    };

    int n = p.size();
    build(0, 0, n-1);
  }

  i64 query_min(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return min_vals_[i];
    }
    if (tl > qr || tr < ql) {
      return 1e18;
    }

    int tm = tl + (tr - tl) / 2;
    return min(
      query_min(i*2+1, tl, tm, ql, min(qr, tm)),
      query_min(i*2+2, tm+1, tr, max(ql, tm+1), qr)
    );
  };

  i64 query_max(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return max_vals_[i];
    }
    if (tl > qr || tr < ql) {
      return -1e18;
    }

    int tm = tl + (tr - tl) / 2;
    return max(
      query_max(i*2+1, tl, tm, ql, min(qr, tm)),
      query_max(i*2+2, tm+1, tr, max(ql, tm+1), qr)
    );
  };

 private:
  vector<i64> min_vals_, max_vals_;
};
 
void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<i64> p = a;
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i] + p[i-1];
  }

  // find the first element on the left that is greater than a[i]
  vector<int> left(n+1, -1);
  vector<int> s;
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && a[i] > a[s.back()]) {
      left[s.back()] = i;
      s.pop_back();
    }
    s.push_back(i);
  }

  // cout << "left:";
  // for (int i = 0; i <= n; ++i) cout << left[i] << " ";
  // cout << endl;

  // find the first element on the right that is greater than a[i]
  s.clear();
  vector<int> right(n+1, -1);
  for (int i = 1; i <= n; ++i) {
    while (!s.empty() && a[i] > a[s.back()]) {
      right[s.back()] = i;
      s.pop_back();
    }
    s.push_back(i);
  }

  // cout << "right:";
  // for (int i = 0; i <= n; ++i) cout << right[i] << " ";
  // cout << endl;

  // build segment tree using prefix sum
  SegmentTree tree(p);

  for (int i = 1; i <= n; ++i) {
    int l = left[i];
    i64 val = 0;
    if (l > 0) {
      val = max(val, p[i-1] - tree.query_min(0, 0, n, l+1, i-1));
    } else {
      val = max(val, p[i-1] - tree.query_min(0, 0, n, 0, i-1));
    }
    // cout << "i=" << i << " lefT: " << val << endl;

    int r = right[i];
    if (r > 0) {
      val = max(val, tree.query_max(0, 0, n, i+1, r-1) - p[i]);
    } else {
      val = max(val, tree.query_max(0, 0, n, i+1, n) - p[i]);
    }

    // cout << "i=" << i << " right: " << val << endl;

    if (val > 0) {
      cout << "NO" << endl;
      return;
    }
  }
 
  cout << "YES" << endl;
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
