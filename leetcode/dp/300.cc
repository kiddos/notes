#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j]+1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1,3,6,7,9,4,10,5,6};
  int ans = Solution().lengthOfLIS(nums);
  assert(ans == 6);

  nums = {0,1,0,3,2,3};
  ans = Solution().lengthOfLIS(nums);
  assert(ans == 4);

  nums = {7,7,7,7,7,7,7};
  ans = Solution().lengthOfLIS(nums);
  assert(ans == 1);

  nums = {10,9,2,5,3,7,101,18};
  ans = Solution().lengthOfLIS(nums);
  assert(ans == 4);
  return 0;
}
