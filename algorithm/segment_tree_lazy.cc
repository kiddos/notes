#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegmentTree {
 public:
  SegmentTree(vector<int> &bits) {
    int n = bits.size();
    int x = ceil(log2(n)) + 1;
    int size = pow(2, x) - 1;
    data_ = vector<int>(size);
    lazy_ = vector<int>(size);

    function<void(int, int, int)> build = [&](int i, int l, int r) {
      if (l > r)
        return;
      if (l == r) {
        data_[i] = bits[l];
        return;
      }

      int m = l + (r - l) / 2;
      build(i * 2 + 1, l, m);
      build(i * 2 + 2, m + 1, r);
      data_[i] = data_[i * 2 + 1] + data_[i * 2 + 2];
    };

    build(0, 0, n - 1);
  }

  void update(int i, int tl, int tr, int l, int r, int val) {
    push(i, tl, tr);

    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      data_[i] += (tr - tl + 1) * val;
      if (tl != tr) {
        lazy_[i * 2 + 1] += val;
        lazy_[i * 2 + 2] += val;
      }
      lazy_[i] = 0;
      return;
    }

    int tm = (tl + tr) / 2;
    update(i * 2 + 1, tl, tm, l, r, val);
    update(i * 2 + 2, tm + 1, tr, l, r, val);
    data_[i] = data_[i * 2 + 1] + data_[i * 2 + 2];
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);

    if (tr < ql || tl > qr) {
      return 0;
    }

    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    int tm = (tl + tr) / 2;
    return query(i * 2 + 1, tl, tm, ql, qr) +
           query(i * 2 + 2, tm + 1, tr, ql, qr);
  }

 private:
  vector<int> data_;
  vector<int> lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      data_[i] += (tr - tl + 1) * lazy_[i];
      if (tl != tr) {
        lazy_[i * 2 + 1] = lazy_[i];
        lazy_[i * 2 + 2] = lazy_[i];
      }
      lazy_[i] = 0;
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> a = {1, 4, 6, 2, 3, 9, 10, 3, 6};
  int n = a.size();
  SegmentTree tree(a);

  for (int i = 0; i < n;++i) cout << tree.query(0, 0, n-1, i, i) << " ";
  cout << endl;

  tree.update(0, 0, n-1, 3, 6, 6);

  for (int i = 0; i < n;++i) cout << tree.query(0, 0, n-1, i, i) << " ";
  cout << endl;

  return 0;
}
