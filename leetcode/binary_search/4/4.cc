#include <bits/stdc++.h>

using namespace std;

// Median of Two Sorted Arrays
//
// this is easy to do in linear time
//
// hard to do this in log time
// if we need something to be done in log time, we should think binary search
//
// we can divide both nums1 and nums2 into 2 parts, the smaller and larger part
// nums1[0], .... nums1[m1-1] | nums1[m1], ... nums[n1-1]
// nums2[0], .... nums2[m2-1] | nums2[m2], ... nums[n2-1]
//
// we know if the left side has m1 elements, right side should have n1-m1
// elements
//  => if left side has m1+m2 elements, right side should have n1+n2-m1-m2
//  elements
//  => median => left side and right side should have same amount of elements
//  => m1+m2 = n1+n2-m1-m2
//  => 2 * (m1+m2) = n1+n2
//  => m1 + m2 = (n1+n2) / 2
//  => m2 = (n1+n2) / 2 - m1 (even size case)
//
//  for odd size case: m2 = (n1+n2+1) / 2 - m1
//  it turns out odd case also works for even case
//
// binary search the point where nums1[m1-1] <= nums2[m2] and nums2[m2-1] <=
// nums1[m1]

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    int l = 0, r = nums1.size();
    int a = nums1.size(), b = nums2.size();
    while (l <= r) {
      int m1 = l + (r - l) / 2;
      int m2 = (a + b + 1) / 2 - m1;
      int a1 = m1 - 1 >= 0 ? nums1[m1 - 1] : numeric_limits<int>::min();
      int a2 = m1 < a ? nums1[m1] : numeric_limits<int>::max();
      int b1 = m2 - 1 >= 0 ? nums2[m2 - 1] : numeric_limits<int>::min();
      int b2 = m2 < b ? nums2[m2] : numeric_limits<int>::max();
      if (a1 <= b2 && b1 <= a2) {
        if ((a + b) % 2 == 0) {
          return (max(a1, b1) + min(a2, b2)) / 2.0;
        }
        return max(a1, b1);
      }

      if (a1 > b2) {
        r = m1 - 1;
      } else {
        l = m1 + 1;
      }
    }
    return 0;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  double ans = Solution().findMedianSortedArrays(nums1, nums2);
  assert(abs(ans - 2.0) <= 1e-6);

  nums1 = {1, 3};
  nums2 = {2, 4};
  ans = Solution().findMedianSortedArrays(nums1, nums2);
  assert(abs(ans - 2.5) <= 1e-6);
  return 0;
}
