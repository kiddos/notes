#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_A = 2000000;
constexpr int SIZE = 2 * MAX_A;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(4 * n) {}

  void update(int i, int tl, int tr, int idx, int x) {
    if (tl > tr) {
      return;
    }

    if (tl == tr) {
      data_[i] = x;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (idx <= tm) update(i * 2 + 1, tl, tm, idx, x);
    else update(i * 2 + 2, tm + 1, tr, idx, x);
    data_[i] = max(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (tl > tr) {
      return 0;
    }
    if (tl >= ql && tr <= qr) {
      return data_[i];
    }
    if (tl > qr || tr < ql) {
      return 0;
    }

    int tm = tl + (tr - tl) / 2;
    return max(
      query(i * 2 + 1, tl, tm, ql, min(qr, tm)), 
      query(i * 2 + 2, tm + 1, tr, max(tm + 1, ql), qr)
    );
  }

  int query_first_greater(int k) {
    int l = 1, r = SIZE;
    int ans = MAX_A + 1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int max_len = query(0, 0, SIZE, 1, mid);
      if (max_len >= k) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }

 private:
  vector<int> data_;
};

SegmentTree tree(SIZE + 1);

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<int, int> miss;
  for (int i = 0, last = 0; i < n; ++i) {
    if (a[i] - last > 1) {
      int l = last + 1;
      int r = a[i] - 1;
      miss[r] = l;
    }
    last = a[i];
  }
  miss[SIZE] = a.back() + 1;

  for (auto& [r, l] : miss) {
    int len = r - l + 1;
    tree.update(0, 0, SIZE, l, len);
  }

  int m = 0;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    char c = '\0';
    cin >> c;
    if (c == '+') {
      int x = 0;
      cin >> x;

      auto it = miss.lower_bound(x);
      if (it != miss.end() && it->second <= x) {
        pair<int, int> i1 = {it->second, x-1};
        pair<int, int> i2 = {x+1, it->first};
        tree.update(0, 0, SIZE, it->second, 0);
        miss.erase(it);
        if (i1.first <= i1.second) {
          miss[i1.second] = i1.first;
          tree.update(0, 0, SIZE, i1.first, i1.second - i1.first + 1);
        }
        if (i2.first <= i2.second) {
          miss[i2.second] = i2.first;
          tree.update(0, 0, SIZE, i2.first, i2.second - i2.first + 1);
        }
      }
    } else if (c == '-') {
      int x = 0;
      cin >> x;

      pair<int,int> i1 = {x, x};
      auto it = miss.lower_bound(x);
      if (it != miss.end() && it->second == x + 1) {
        i1.second = it->first;
        tree.update(0, 0, SIZE, it->second, 0);
        miss.erase(it);
      }
      it = miss.upper_bound(x);
      if (it != miss.begin() && prev(it)->first == x - 1) {
        i1.first = prev(it)->second;
        tree.update(0, 0, SIZE, prev(it)->second, 0);
        miss.erase(prev(it));
      }
      tree.update(0, 0, SIZE, i1.first, i1.second - i1.first + 1);
      miss[i1.second] = i1.first;
    } else if (c == '?') {
      int k = 0;
      cin >> k;
      int d = tree.query_first_greater(k);
      cout << d << " ";
    }

    // for (auto &[end, start] : miss) {
    //   cout << start << "~" << end << ", ";
    // }
    // cout << endl;
  }
  cout << endl;

  for (auto& [r, l] : miss) {
    tree.update(0, 0, SIZE, l, 0);
  }
  assert(tree.query(0, 0, SIZE, 0, SIZE) == 0);
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
