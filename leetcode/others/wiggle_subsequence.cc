#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i-1]) up = down + 1;
      if (nums[i] < nums[i-1]) down = up + 1;
    }
    return max(up, down);
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int ans = Solution().wiggleMaxLength(nums);
    cout << ans << endl;
  }
  return 0;
}
