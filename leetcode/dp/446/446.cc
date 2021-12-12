#include <bits/stdc++.h>

using namespace std;

// Arithmetic Slices II - Subsequence
//
// For Arithmetic problem, should think about diff
// diff needs at least 2 numbers, so the complexity should be at least O(n^2)
// which is fine for this problem

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    vector<unordered_map<long, int>> dp(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long diff = (long)nums[i] - (long)(nums[j]);
        ans += dp[j][diff];
        dp[i][diff] += dp[j][diff] + 1;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {2, 4, 6, 8, 10};
  int ans = Solution().numberOfArithmeticSlices(nums);
  assert(ans == 7);

  nums = {7, 7, 7, 7, 7};
  ans = Solution().numberOfArithmeticSlices(nums);
  assert(ans == 16);

  return 0;
}
