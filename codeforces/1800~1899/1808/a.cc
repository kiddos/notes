#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_VAL = 1e6;

int lucky(int a) {
  int max_d = 0, min_d = 10;
  while (a > 0) {
    int d = a % 10;
    max_d = max(max_d, d);
    min_d = min(min_d, d);
    a /= 10;
  }
  return max_d - min_d;
}

class SegmentTree {
 public:
  void set_data(vector<int>& data) {

    function<void(int,int,int)> build = [&](int i, int l, int r) {
      if (l > r) return;
      if (l == r) {
        max_vals_[i] = {data[l], l};
        return;
      }

      int m = l + (r-l) / 2;
      build(i*2+1, l, m);
      build(i*2+2, m+1, r);
      max_vals_[i] = max(max_vals_[i*2+1], max_vals_[i*2+2]);
    };

    int n = data.size();
    max_vals_ = vector<pair<int,int>>(n*4);
    build(0, 0, n-1);
  }

  pair<int,int> query(int i, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) {
      return max_vals_[i];
    }
    if (tr < ql || tl > qr) {
      return {-1, 0};
    }
    int tm = tl + (tr-tl) / 2;
    return max(query(i*2+1, tl, tm, ql, min(qr, tm)),
               query(i*2+2, tm+1, tr, max(ql, tm+1), qr));
  }

 private:
  vector<pair<int,int>> max_vals_;
};

SegmentTree tree;

void precompute() {
  vector<int> luckiness(MAX_VAL+1);
  for (int i = 1; i <= MAX_VAL; ++i) {
    luckiness[i] = lucky(i);
  }

  tree.set_data(luckiness);
}

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;

  auto ans = tree.query(0, 0, MAX_VAL, l, r);
  cout << ans.second << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
