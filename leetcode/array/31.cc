#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    for (int i = n-2; i >= 0; --i) {
      for (int j = n-1; j > i; --j) {
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          reverse(nums.begin()+i+1, nums.end());
          return;
        }
      }
    }
    reverse(nums.begin(), nums.end());
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums, ans;
  nums = { 1,2,3,4,5,4,3,2,1 };
  Solution().nextPermutation(nums);
  ans = {1,2,3,5,1,2,3,4,4};
  for (int i = 0; i < nums.size(); ++i) assert(ans[i] == nums[i]);

  nums = { 1,2,3 };
  Solution().nextPermutation(nums);
  ans = {1,3,2};
  for (int i = 0; i < nums.size(); ++i) assert(ans[i] == nums[i]);

  nums = { 3,2,1 };
  Solution().nextPermutation(nums);
  ans = {1,2,3};
  for (int i = 0; i < nums.size(); ++i) assert(ans[i] == nums[i]);

  nums = { 1,2,3,4,5,6,7,8,9 };
  Solution().nextPermutation(nums);
  ans = {1,2,3,4,5,6,7,9,8};
  for (int i = 0; i < nums.size(); ++i) assert(ans[i] == nums[i]);

  nums = { 1,1,5,2,1 };
  Solution().nextPermutation(nums);
  ans = {1,2,1,1,5};
  for (int i = 0; i < nums.size(); ++i) assert(ans[i] == nums[i]);

  // code here...
  return 0;
}
