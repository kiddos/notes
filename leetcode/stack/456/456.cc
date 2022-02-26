#include <bits/stdc++.h>

using namespace std;

// 132 Pattern
//
// this one is a little tricky to think of
// the trick is to get the 32 part by iterating from the back
// make a decreasing stack starting from the back
// the current number will be the largest number = 3
// need to remember the second largest = 2
// before this operation, if there is a number smaller than 2, then there is the answer

class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    stack<int> s;
    int n = nums.size();
    int second = numeric_limits<int>::min();
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] < second) return true;
      while (!s.empty() && nums[i] > s.top()) {
        second = s.top();
        s.pop();
      }
      s.push(nums[i]);
    }
    return false;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums;
  bool ans = false;

  nums = {1, 2, 3, 4};
  ans = Solution().find132pattern(nums);
  assert(!ans);

  nums = {3, 1, 4, 2};
  ans = Solution().find132pattern(nums);
  assert(ans);

  nums = {-1, 3, 2, 0};
  ans = Solution().find132pattern(nums);
  assert(ans);
  return 0;
}
