#include <bits/stdc++.h>

using namespace std;

// Bitwise AND of Numbers Range
//
// this is my original idea
// check if both left and right has this bit and
// the distance between left and right is less than (1<<bit)
// if true, then the answer should have this bit

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int ans = 0;
    for (int bit = 0; bit < 32; ++bit) {
      int b = 1 << bit;
      if ((left & b) && (right & b) && right - left < b) {
        ans |= b;
      }
    }
    return ans;
  }
};

// this is a different way to think for this problem
// since we are doing AND operation
// only bits that will be a part of the answer is some prefix of left and right
// that is the same so keep removing the suffix of left and right until they are
// the same

class Solution2 {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int b = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      b++;
    }
    return left << b;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int left = 5, right = 7;
  int ans = Solution().rangeBitwiseAnd(left, right);
  assert(ans == 4);

  ans = Solution2().rangeBitwiseAnd(left, right);
  assert(ans == 4);

  return 0;
}
