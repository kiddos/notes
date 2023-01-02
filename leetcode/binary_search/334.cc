#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    set<int> s;
    for (int n : nums) {
      if (s.count(n)) continue;
      auto p = s.insert(n);
      auto it = p.first;
      if (++it != s.end()) {
        s.erase(it);
      }
    }
    return s.size() >= 3;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // code here...
  vector<int> nums = { 1,2,3,4,5 };
  bool ans = Solution().increasingTriplet(nums);
  assert(ans);

  nums = { 5,4,3,2,1 };
  ans = Solution().increasingTriplet(nums);
  assert(!ans);

  nums = { 2,1,5,0,4,6 };
  ans = Solution().increasingTriplet(nums);
  assert(ans);
  return 0;
}
