#include <bits/stdc++.h>

using namespace std;

// Subarrays with K Different Integers
//
// O(n^2) is trivial, but O(n) is hard
// the problem will require O(n) solution
// the trick is to compute how many sub array with at most k distinct numbers -
// how many sub array with at most k-1 distinct numbers
//
// Lees explanation:
// exactly(K) = atMost(K) - atMost(K-1)

class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    unordered_map<int, int> count1, count2;
    int j1 = 0, j2 = 0;
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      count1[nums[i]]++;
      count2[nums[i]]++;
      while (j1 < n && count1.size() > k) {
        int a = nums[j1++];
        if (--count1[a] == 0) count1.erase(a);
      }

      while (j2 < n && count2.size() >= k) {
        int a = nums[j2++];
        if (--count2[a] == 0) count2.erase(a);
      }

      ans += j2 - j1;
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;

  int ans = Solution().subarraysWithKDistinct(nums, k);
  assert(ans == 7);

  nums = {1, 2, 1, 3, 4};
  k = 3;
  ans = Solution().subarraysWithKDistinct(nums, k);
  assert(ans == 3);
  return 0;
}
