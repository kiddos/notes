#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(vector<int>& a) {
    int n = a.size();
    data_ = vector<int>(n*4);
    
    function<void(int,int,int)> build = [&](int i, int tl, int tr) {
      if (tl == tr) {
        data_[i] = a[tl];
        return;
      }

      int tm = tl + (tr - tl) / 2;
      build(i*2+1, tl, tm);
      build(i*2+2, tm+1, tr);
      data_[i] = max(data_[i*2+1], data_[i*2+2]);
    };

    build(0, 0, n-1);
  }

  int query_max(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql & tr <= qr) {
      return data_[i];
    }

    if (tl > qr || tr < ql) {
      return 0;
    }

    int tm = tl + (tr - tl) / 2;
    return max(query_max(i*2+1, tl, tm, ql, min(qr, tm)),
               query_max(i*2+2, tm+1, tr, max(ql, tm+1), qr));
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) cin >> b[i];

  vector<int> indices(n+1, -1);
  vector<int> left(n+1);
  for (int i = 1; i <= n; ++i) {
    indices[a[i]] = i;
    left[i] = indices[b[i]];
  }
  fill(indices.begin(), indices.end(), -1);
  vector<int> right(n+1);
  for (int i = n; i >= 1; --i) {
    indices[a[i]] = i;
    right[i] = indices[b[i]];
  }

  vector<int> right_bound(n+1, n);
  vector<int> s;
  for (int i = 1; i <= n; ++i) {
    while (!s.empty() && b[s.back()] > b[i]) {
      right_bound[s.back()] = i-1;
      s.pop_back();
    }
    s.push_back(i);
  }

  // cannot do this for monotonic stack
  // for (int i = 1; i <= n; ++i) {
  //   while (!s.empty() && b[s.back()] < a[i]) {
  //     right_bound[s.back()] = min(right_bound[s.back()], i-1);
  //     s.pop_back();
  //   }
  //   s.push_back(i);
  // }

  s.clear();
  vector<int> left_bound(n+1, 1);
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && b[s.back()] > b[i]) {
      left_bound[s.back()] = i+1;
      s.pop_back();
    }
    s.push_back(i);
  }

  s.clear();

  // cout << "left: " << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << left[i] << " ";
  // }
  // cout << endl;
  // cout << "right: " << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << right[i] << " ";
  // }
  // cout << endl;

  SegmentTree tree(a);
  for (int i = 1; i <= n; ++i) {
    if (b[i] < a[i]) {
      cout << "NO" << endl;
      return;
    }

    bool possible = false;
    if (left[i] > 0) {
      if (left[i] >= left_bound[i]) {
        int max_a = tree.query_max(0, 0, n, left[i], i);
        if (max_a <= b[i]) {
          possible = true;
        }
      }
    }

    if (right[i] > 0) {
      if (right[i] <= right_bound[i]) {
        int max_a = tree.query_max(0, 0, n, i, right[i]);
        if (max_a <= b[i]) {
          possible = true;
        }
      }
    }

    if (!possible) {
      // cout << "index=" << i << endl;
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
