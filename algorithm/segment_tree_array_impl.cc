#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
 public:
  SegmentTree(vector<int>& nums) : n(nums.size()), tree_(nums.size() * 4) {
    function<void(int, int, int)> build = [&](int i, int tl, int tr) {
      if (tl == tr) {
        tree_[i] = nums[tl];
      } else {
        int tm = tl + (tr - tl) / 2;
        build(i * 2 + 1, tl, tm);
        build(i * 2 + 2, tm + 1, tr);
        tree_[i] = tree_[i * 2 + 1] + tree_[i * 2 + 2];
      }
    };

    build(0, 0, nums.size() - 1);
  }

  void update(int index, int val) { update_tree(0, 0, n - 1, index, val); }

  void update_tree(int i, int tl, int tr, int index, int val) {
    if (tl == tr) {
      tree_[i] = val;
    } else {
      int tm = tl + (tr - tl) / 2;
      if (index <= tm) {
        update_tree(i * 2 + 1, tl, tm, index, val);
      } else {
        update_tree(i * 2 + 2, tm + 1, tr, index, val);
      }
      tree_[i] = tree_[i * 2 + 1] + tree_[i * 2 + 2];
    }
  }

  int query(int left, int right) {
    return query_tree(0, 0, n - 1, left, right);
  }

  int query_tree(int i, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
      return tree_[i];
    }

    int tm = tl + (tr - tl) / 2;
    return query_tree(i * 2 + 1, tl, tm, l, min(r, tm)) +
           query_tree(i * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
  }

 private:
  int n;
  vector<int> tree_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> data = {7, 2, 7, 2, 0};
  SegmentTree tree(data);
  tree.update(4, 6);
  tree.update(0, 2);
  tree.update(0, 9);
  assert(tree.query(4, 4) == 6);
  tree.update(3, 8);
  assert(tree.query(0, 4) == 32);
  tree.update(4, 1);
  assert(tree.query(0, 3) == 26);
  assert(tree.query(0, 4) == 27);
  tree.update(0, 4);
  return 0;
}
