#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int ans = 0;
    for (int n : nums) {
      int rest = k-n;
      if (count.count(rest)) {
        ans++;
        count[rest]--;
        if (count[rest] == 0) count.erase(rest);
      } else {
        count[n]++;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums;
  int k, ans;
  nums = { 1,2,3,4 };
  k = 5;
  ans = Solution().maxOperations(nums, k);
  assert(ans == 2);

  nums = { 3,1,3,4,3 };
  k = 6;
  ans = Solution().maxOperations(nums, k);
  assert(ans == 1);


  // code here...
  return 0;
}
