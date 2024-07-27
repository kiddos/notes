#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int max_value = nums[0];
    int min_value = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] < 0) swap(max_value, min_value);
      max_value = max(nums[i], max_value * nums[i]);
      min_value = min(nums[i], min_value * nums[i]);
      ans = max(ans, max_value);
    }
    return ans;
  }
};

int main(void) {
  constexpr int n = 1000;
  default_random_engine gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(-10, 10);
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = dist(gen);
  }

  int ans = Solution().maxProduct(nums);
  cout << ans << endl;
  return 0;
}
