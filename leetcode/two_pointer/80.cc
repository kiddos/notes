#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums) {
      if (i < 2 || n > nums[i-2]) {
        nums[i++] = n;
      }
    }
    return i;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1,1,1,2,2,3};
  int len = Solution().removeDuplicates(nums);
  for (int i = 0; i < len; ++i) cout << nums[i] << ",";
  cout << endl;
  return 0;
}
