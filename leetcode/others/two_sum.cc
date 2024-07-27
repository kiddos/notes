#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {0, 0};
  }
};

class Solution2 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> table;
    for (int i = 0; i < n; ++i) {
      if (table.count(target-nums[i])) {
        return {table[target-nums[i]], i};
      }
      table[nums[i]] = i;
    }
    return {0, 0};
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int target = 0;
    cin >> target;

    vector<int> ans = Solution1().twoSum(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;
    ans = Solution2().twoSum(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;
  }
  return 0;
}
