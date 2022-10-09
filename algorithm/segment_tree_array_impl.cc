#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
 public:
  SegmentTree(vector<int>& nums) {
    int n = nums.size();
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    sums_ = vector<int>(max_size);
    function<void(int, int, int)> build_tree = [&](int i, int tl, int tr) {
      if (tl == tr) {
        sums_[i] = nums[tl];
        return;
      }
      int tm = tl + (tr - tl) / 2;
      build_tree(i * 2 + 1, tl, tm);
      build_tree(i * 2 + 2, tm + 1, tr);

      update(i);
    };

    build_tree(0, 0, n - 1);
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    if (ql > qr) return 0;
    if (tr < ql || tl > qr) return 0;
    if (tl >= ql && tr <= qr) return sums_[i];

    int tm = tl + (tr - tl) / 2;
    return query(i * 2 + 1, tl, tm, ql, min(tm, qr)) +
           query(i * 2 + 2, tm + 1, tr, max(tm, ql), qr);
  }

  void update(int i, int tl, int tr, int index, int val) {
    if (tl == tr) {
      sums_[i] = val;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (index <= tm)
      update(i * 2 + 1, tl, tm, index, val);
    else
      update(i * 2 + 2, tm + 1, tr, index, val);
    update(i);
  }

 private:
  vector<int> sums_;

  inline void update(int i) { sums_[i] = sums_[i * 2 + 1] + sums_[i * 2 + 2]; }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> data = {7, 2, 7, 2, 0};
  SegmentTree tree(data);
  const int n = data.size();
  tree.update(0, 0, n - 1, 4, 6);
  tree.update(0, 0, n - 1, 0, 2);
  tree.update(0, 0, n - 1, 0, 9);
  assert(tree.query(0, 0, n - 1, 4, 4) == 6);
  tree.update(0, 0, n - 1, 3, 8);
  assert(tree.query(0, 0, n - 1, 0, 4) == 32);
  tree.update(0, 0, n - 1, 4, 1);
  assert(tree.query(0, 0, n - 1, 0, 3) == 26);
  assert(tree.query(0, 0, n - 1, 0, 4) == 27);
  tree.update(0, 0, n - 1, 0, 4);
  return 0;
}
