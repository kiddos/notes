#include <bits/stdc++.h>

using namespace std;

// Find the Most Competitive Subsequence
//
// think of increasing stack

class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      while ((n - i) > k - (int)ans.size() && !ans.empty() &&
             nums[i] < ans.back()) {
        ans.pop_back();
      }
      ans.push_back(nums[i]);
    }
    ans.resize(k);
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums, ans, target;
  int k;

  nums = {3, 5, 2, 6};
  k = 2;
  ans = Solution().mostCompetitive(nums, k);
  target = {2, 6};
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  return 0;
}
