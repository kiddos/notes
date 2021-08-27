#include <bits/stdc++.h>

using namespace std;

// Longest Consecutive Sequence
//
// O(n)
// keep track of the size of boundary:
// boundary[left] = right - left+1
// boundary[right] = right - left+1
//
// so when we see a number update boundary[n], boundary[n-left], boundary[n+right]

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> boundary;
    int ans = 0;
    for (int num : nums) {
      if (boundary.count(num)) continue;

      int left = boundary.count(num - 1) ? boundary[num - 1] : 0;
      int right = boundary.count(num + 1) ? boundary[num + 1] : 0;
      int new_size = left + right + 1;
      ans = max(ans, new_size);
      boundary[num] = new_size;
      boundary[num - left] = new_size;
      boundary[num + right] = new_size;
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int ans = Solution().longestConsecutive(nums);
  assert(ans == 9);

  nums = {100, 4, 200, 1, 3, 2};
  ans = Solution().longestConsecutive(nums);
  assert(ans == 4);

  nums = {1, 1, 2, 0, 1};
  ans = Solution().longestConsecutive(nums);
  assert(ans == 3);

  return 0;
}
