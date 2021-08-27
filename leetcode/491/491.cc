#include <bits/stdc++.h>

using namespace std;

// Increasing Subsequences
//
// the tricky part is to generate numbers without duplicates
// use hash set to avoid duplicates

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    function<void(int,vector<int>&)> backtrack = [&](int index, vector<int>& seq) {
      if (seq.size() > 1) ans.push_back(seq);
      unordered_set<int> added;
      for (int i = index; i < n; ++i) {
        if (added.count(nums[i])) continue;
        if (seq.empty() || seq.back() <= nums[i]) {
          added.insert(nums[i]);
          seq.push_back(nums[i]);
          backtrack(i+1, seq);
          seq.pop_back();
        }
      }
    };

    vector<int> seq;
    backtrack(0, seq);
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1,2,3,4,5,6,6,6};
  vector<vector<int>> ans = Solution().findSubsequences(nums);
  for (vector<int>& row : ans) {
    for (int num : row) cout << num << " ";
    cout << endl;
  }
  return 0;
}
