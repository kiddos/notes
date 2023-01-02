#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    set<int> s;
    for (int n : nums) {
      if (s.count(n)) continue;
      auto p = s.insert(n);
      auto it = p.first;
      if (++it != s.end()) {
        s.erase(it);
      }
    }
    return s.size();
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = { 10,9,2,5,3,7,101,18 };
  int ans = Solution().lengthOfLIS(nums);
  assert(ans == 4);

  nums = { 0,1,0,3,2,3 };
  ans = Solution().lengthOfLIS(nums);
  assert(ans == 4);

  nums = { 7,7,7,7,7,7,7 };
  ans = Solution().lengthOfLIS(nums);
  assert(ans == 1);
  return 0;
}
