#include <bits/stdc++.h>

using namespace std;

// Find Minimum in Rotated Sorted Array II
//
// divide and conquer solution
// the problem is tricky because the nums could have duplicates
// which makes binary search a little weird to think of
//
// the idea is the following
// if the start number is strictly small than the end number
//  -> then the start number is the smallest because the current range of number is not rotated
// if there is only 2 numbers return the smaller one
// else we don't really know where is smallest number is
// so we can only increament start range by 1

class Solution {
 public:
  int findMin(vector<int>& nums) {
    function<int(int, int)> find = [&](int l, int r) {
      if (l + 1 >= r) return min(nums[l], nums[r]);
      if (nums[l] < nums[r]) return nums[l];
      return find(l + 1, r);
    };
    return find(0, nums.size() - 1);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {2, 2, 2, 0, 1};
  int ans = Solution().findMin(nums);
  assert(ans == 0);

  return 0;
}
