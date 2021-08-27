#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    return maxSubArray(nums, 0, n-1);
  }

 private:
  int maxSubArray(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int mid = l + (r-l)/2;
    int left_ans = maxSubArray(nums, l, mid);
    int right_ans = maxSubArray(nums, mid+1, r);
    int left_max = nums[mid];
    for (int i = mid, s = 0; i >= l; --i) {
      s += nums[i];
      left_max = max(left_max, s);
    }
    int right_max = nums[mid+1];
    for (int i = mid+1, s = 0; i <= r; ++i) {
      s += nums[i];
      right_max = max(right_max, s);
    }
    return max({left_ans, right_ans, left_max+right_max});
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
  int ans = Solution().maxSubArray(input);
  assert(ans == 6);

  input = {1};
  ans = Solution().maxSubArray(input);
  assert(ans == 1);

  input = {0};
  ans = Solution().maxSubArray(input);
  assert(ans == 0);

  input = {-2147483647};
  ans = Solution().maxSubArray(input);
  assert(ans == -2147483647);

  return 0;
}
