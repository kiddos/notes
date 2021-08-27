#include <bits/stdc++.h>

using namespace std;

// Count of Range Sum
//
// This one is super tough, naive solution O(n^2) is not going to work
// need to think this one in the way that is very similar to 315. Count of
// Smaller Numbers After Self
//
// the problem is to find all the range sum that satisfy the condition (eg.
// sum([i...j]) >= lower && sum([i...j]) <= upper) the naive solution is to
// calculate the prefix sum first in O(n) and try all range sum in O(n^2)
//
// to do this faster,
// we can do a merge sort
// for each prefix sum in the left,
// count the number of right such that satify the condition
//
// what this means is to
// for each index i in the left
//   1. find the first index j in the right such that prefix_sum[j] -
//   prefix_sum[i] >= lower
//   2. find the last index j in the right such that prefix_sum[j] -
//   prefix_sum[i] <= upper
//
// this is quite tricky to implement

class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long> prefix_sum = {0};
    for (int num : nums) prefix_sum.push_back(prefix_sum.back() + (long)num);

    function<int(int, int)> merge_sort = [&](int l, int r) {
      int n = r - l + 1;
      if (n <= 1) return 0;
      int mid = l + (r - l) / 2;
      int ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
      vector<long> arr(n);
      int j = mid + 1;
      for (int i = l, k = 0, p = mid + 1, q = mid + 1; i <= mid; ++i, ++k) {
        while (p <= r && prefix_sum[p] - prefix_sum[i] < lower) p++;
        while (q <= r && prefix_sum[q] - prefix_sum[i] <= upper) q++;
        while (j <= r && prefix_sum[j] < prefix_sum[i])
          arr[k++] = prefix_sum[j++];
        arr[k] = prefix_sum[i];
        ans += q - p;
      }
      move(arr.begin(), arr.begin() + (j - l), prefix_sum.begin() + l);
      return ans;
    };
    return merge_sort(0, prefix_sum.size() - 1);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {-2, 5, -1};
  int lower = -2;
  int upper = 2;
  int ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 3);

  nums = {0};
  lower = 0;
  upper = 0;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 1);

  nums = {-2, -1, -2, -1, -3, -2};
  lower = 1;
  upper = 6;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 0);

  nums = {2147483647, -2147483648, -1, 0};
  lower = -1;
  upper = 0;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 4);

  return 0;
}
