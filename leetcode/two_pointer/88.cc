#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int last = m + n - 1, i = m - 1, j = n - 1;
    while (j >= 0) {
      nums1[last--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;
  Solution().merge(nums1, m, nums2, n);
  vector<int> ans = {1, 2, 2, 3, 5, 6};
  for (int i = 0; i < nums1.size(); ++i) assert(nums1[i] == ans[i]);
  return 0;
}
