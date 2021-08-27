#include <bits/stdc++.h>

using namespace std;

// Maximum Subarray
//
// basic kadane's algorithm would work
// kadane's algorithm is sort of dp

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int current = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      current = max(current + nums[i], nums[i]);
      ans = max(ans, current);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int ans = Solution().maxSubArray(nums);
  assert(ans == 6);

  nums = {1};
  ans = Solution().maxSubArray(nums);
  assert(ans == 1);

  nums = {5, 4, -1, 7, 8};
  ans = Solution().maxSubArray(nums);
  assert(ans == 23);

  return 0;
}
