#include <bits/stdc++.h>

using namespace std;

// Single Number III
//
// use xor to get the 2 number xor together
// to find the two number, we choose a bit in the xor-together number
// one of the two number will have that bit, and other other does not
// so we can separate the number into 2 group

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    long x = 0;
    for (int num : nums) x ^= num;

    long y = x & -x;
    int a = 0, b = 0;
    for (int num : nums) {
      if (num & y) {
        a ^= num;
      } else {
        b ^= num;
      }
    }
    return {a, b};
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1, 1, 0, -2147483648};

  vector<int> ans = Solution().singleNumber(nums);

  return 0;
}
