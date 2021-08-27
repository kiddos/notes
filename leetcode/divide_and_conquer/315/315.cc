#include <bits/stdc++.h>

using namespace std;

// Count of Smaller Numbers After Self
//
// do a merge sort on the array
// the answer for the smaller number will be the number of larger number
// eg. ans[arr[i].index] += j


class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) pairs.push_back({i, nums[i]});
    vector<int> ans(n);
    merge_sort(pairs, 0, n - 1, ans);
    return ans;
  }

  void merge_sort(vector<pair<int, int>>& arr, int l, int r, vector<int>& ans) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid, ans);
    merge_sort(arr, mid + 1, r, ans);
    vector<pair<int, int>> pairs(r - l + 1);
    for (int i = l, j = mid + 1, k = 0; i <= mid || j <= r;) {
      if (j > r || (i <= mid && arr[i].second <= arr[j].second)) {
        ans[arr[i].first] += j - mid - 1;
        pairs[k++] = arr[i++];
      } else {
        pairs[k++] = arr[j++];
      }
    }
    move(pairs.begin(), pairs.end(), arr.begin() + l);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {5, 2, 6, 1};
  vector<int> target = {2, 1, 1, 0};
  vector<int> ans = Solution().countSmaller(nums);
  for (int i = 0; i < target.size(); ++i) assert(target[i] == ans[i]);

  nums = {2, 0, 1};
  target = {2, 0, 0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < target.size(); ++i) assert(target[i] == ans[i]);

  return 0;
}
