#include <bits/stdc++.h>

using namespace std;

// Count of Smaller Numbers After Self
//
// the idea is to use merge sort
// when output to target array
// count the number of steps where the second half has advance
// which will be the answer

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<pair<int, int>> pairs;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      pairs.push_back({i, nums[i]});
    }

    vector<int> ans(n);
    function<void(int, int)> merge_sort = [&](int l, int r) {
      if (l == r - 1) return;
      int m = l + (r - l) / 2;
      merge_sort(l, m);
      merge_sort(m, r);
      vector<pair<int, int>> result(r - l);
      for (int i = l, j = m, k = 0; i < m || j < r;) {
        int a = i < m ? pairs[i].second : numeric_limits<int>::max();
        int b = j < r ? pairs[j].second : numeric_limits<int>::max();
        if (a <= b) {
          if (i < m) ans[pairs[i].first] += j - m;
          result[k++] = pairs[i++];
        } else {
          result[k++] = pairs[j++];
        }
      }
      move(result.begin(), result.end(), pairs.begin() + l);
    };
    merge_sort(0, n);

    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {5, 2, 6, 1};
  vector<int> target = {2, 1, 1, 0};
  vector<int> ans = Solution().countSmaller(nums);
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  nums = {-1};
  target = {0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  nums = {-1, -1};
  target = {0, 0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  nums = {5, 2, 6};
  target = {1, 0, 0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  target = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  target = {8, 7, 6, 5, 4, 3, 2, 1, 0};
  ans = Solution().countSmaller(nums);
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  return 0;
}
