#include <bits/stdc++.h>

using namespace std;

// Kth Largest Element in an Array
//
// learn quick select algorithm average complexity should be O(n)

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    k--;
    function<int(int, int)> partition = [&](int l, int r) {
      if (l == r) return l;
      int pivot = nums[r];
      int i = l;
      for (int j = l; j < r; ++j) {
        if (nums[j] >= pivot) {
          swap(nums[i++], nums[j]);
        }
      }
      swap(nums[i], nums[r]);
      return i;
    };

    function<int(int, int)> quick_select = [&](int l, int r) {
      int pivot_index = partition(l, r);
      if (pivot_index == k)
        return nums[pivot_index];
      else if (pivot_index > k)
        return quick_select(l, pivot_index - 1);
      else
        return quick_select(pivot_index + 1, r);
    };

    return quick_select(0, nums.size() - 1);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums;
  int k, ans;

  nums = {3, 2, 1, 5, 6, 4};
  k = 2;
  ans = Solution().findKthLargest(nums, k);
  assert(ans == 5);

  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  k = 4;
  ans = Solution().findKthLargest(nums, k);
  assert(ans == 4);

  nums = {5, 2, 4, 1, 3, 6, 0};
  k = 4;
  ans = Solution().findKthLargest(nums, k);
  assert(ans == 3);
  return 0;
}
