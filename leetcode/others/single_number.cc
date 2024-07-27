#include <bits/stdc++.h>

using namespace std;


class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int diff = 0;
    for (int n : nums) diff ^= n;
    // diff = a ^ b

    // least significant digit
    diff = diff & (-diff);
    int a = 0, b = 0;
    for (int n : nums) {
      if (n & diff) a ^= n;
      else b ^= n;
    }
    return {a, b};
  }
};

class Solution1 {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int diff = 0;
    for (int n : nums) diff ^= n;

    int bit = 0;
    for (int i = 0; i < 32; ++i) {
      if (diff & (1 << i)) {
        bit = i;
        break;
      }
    }

    int a = 0, b = 0;
    for (int n : nums) {
      if (n & (1 << bit)) a ^= n;
      else b ^= n;
    }
    return {a, b};
  }
};


int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }

    vector<int> ans = Solution().singleNumber(nums);
    cout << ans[0] << ", " << ans[1] << endl;

    ans = Solution1().singleNumber(nums);
    cout << ans[0] << ", " << ans[1] << endl;
  }
  return 0;
}
