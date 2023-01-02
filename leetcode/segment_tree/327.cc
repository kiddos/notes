#include <bits/stdc++.h>

using namespace std;

struct SegmentTreeNode {
  int count;
  long long min_val, max_val;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(long long min_val, long long max_val)
      : count(0),
        min_val(min_val),
        max_val(max_val),
        left(nullptr),
        right(nullptr) {}
  ~SegmentTreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

SegmentTreeNode* build_tree(vector<long long>& sums, int start, int end) {
  if (start == end) {
    return new SegmentTreeNode(sums[start], sums[end]);
  }
  if (start > end) return nullptr;
  int mid = start + (end - start) / 2;
  SegmentTreeNode* root = new SegmentTreeNode(sums[start], sums[end]);
  root->left = build_tree(sums, start, mid);
  root->right = build_tree(sums, mid + 1, end);
  return root;
}

void update(SegmentTreeNode* root, long long sum, int delta) {
  if (sum > root->max_val || sum < root->min_val) return;
  root->count += delta;
  if (root->left && sum <= root->left->max_val) update(root->left, sum, delta);
  if (root->right && sum >= root->right->min_val)
    update(root->right, sum, delta);
}

int query(SegmentTreeNode* root, long long lower, long long upper) {
  if (lower <= root->min_val && upper >= root->max_val) return root->count;
  if (lower > root->max_val || upper < root->min_val) return 0;
  int left = root->left ? query(root->left, lower, upper) : 0;
  int right = root->right ? query(root->right, lower, upper) : 0;
  return left + right;
}

class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    set<long long> s;
    long long sum = 0;
    for (int num : nums) {
      sum += num;
      s.insert(sum);
    }

    vector<long long> sums(s.begin(), s.end());
    SegmentTreeNode* root = build_tree(sums, 0, sums.size() - 1);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      update(root, sum, 1);
      sum -= nums[i];
      ans += query(root, lower + sum, upper + sum);
    }

    delete root;
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums;
  int lower, upper;
  int ans;
  nums = {-2, 5, -1};
  lower = -2, upper = 2;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 3);

  nums = {-2147483647, 0, -2147483647, 2147483647};
  lower = -564, upper = 3864;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 3);
  return 0;
}
