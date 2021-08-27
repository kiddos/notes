#include <bits/stdc++.h>

using namespace std;

// Maximum XOR of Two Numbers in an Array
//
// one way to do this is using trie
//
// the other way is to try all possibility for all bits for the answer
// we can use the property: A ^ B = C => A ^ C = B
// so if there is a number n1 that n1 ^ answer = n2 and n2 is also in the set
// then answer is one possibility
// try to add 1 bit at a time to the answer
// if we can find n1 and n2 such that n1 ^ answer = n2 then, answer can add that
// bit else answer should not have that bit

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int mask = 0, ans = 0;
    for (int bit = 31; bit >= 0; --bit) {
      mask |= (1 << bit);
      unordered_set<int> s;
      for (int num : nums) s.insert(mask & num);

      int possible = ans | (1 << bit);
      for (int num : s)
        if (s.count(possible ^ num)) {
          ans = possible;
          break;
        }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {3, 10, 5, 25, 2, 8};
  int ans = Solution().findMaximumXOR(nums);
  assert(ans == 28);
  return 0;
}
