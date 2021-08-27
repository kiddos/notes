#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n + 1) {}

  void update(int i, int d) {
    int n = data_.size();
    while (i < n) {
      data_[i] += d;
      i += (i & -i);
    }
  }

  int get(int i) {
    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

 private:
  vector<int> data_;
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    int max_val = numeric_limits<int>::min();
    int min_val = numeric_limits<int>::max();
    for (int num : nums) {
      max_val = max(max_val, num);
      min_val = min(min_val, num);
    }

    vector<int> ans(n);
    FenwickTree tree(max_val - min_val + 1);
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = tree.get(nums[i] - min_val);
      tree.update(nums[i] - min_val + 1, 1);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {5, 2, 6, 1};
  vector<int> target = {2, 1, 1, 0};
  vector<int> ans = Solution().countSmaller(nums);
  for (int i = 0; i < target.size(); ++i) assert(target[i] == ans[i]);

  nums = {2, 0, 1};
  target = {2, 0, 0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < target.size(); ++i) assert(target[i] == ans[i]);
  return 0;
}

