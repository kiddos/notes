#include <bits/stdc++.h>

using namespace std;

// Target Sum
// dp[i][t] means ways to get to t using i numbers
// dp[i][t] = dp[i-1][t-nums[i]] + dp[i-1][t+nums[i]];

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> dp;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int> next_dp;
      for (auto& p : dp) {
        next_dp[p.first + nums[i]] += p.second;
        next_dp[p.first - nums[i]] += p.second;
      }
      dp = move(next_dp);
    }
    return dp[target];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1, 1, 1, 1, 1};
  int ans = Solution().findTargetSumWays(nums, 3);
  assert(ans == 5);

  return 0;
}
