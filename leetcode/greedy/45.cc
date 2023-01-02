#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    int jump = 0;
    int current = 0;
    int end = 0;
    while (current < n) {
      int next_end = end;
      while (current <= end) {
        next_end = max(next_end, current+nums[current]);
        if (next_end >= n-1) return jump+1;
        current++;
      }
      end = next_end;
      jump++;
    }
    return jump;
  }
};

int main(void) {
  vector<int> nums1 = { 2, 3, 0, 1, 4 };
  vector<int> nums2 = { 2, 3, 1, 1, 4 };
  int ans = Solution().jump(nums1);
  cout << ans << endl;
  ans = Solution().jump(nums2);
  cout << ans << endl;
  return 0;
}
