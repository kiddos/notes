#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> length(n, 1);
    vector<int> count(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (length[j] + 1 > length[i]) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          } else if (length[j] + 1 == length[i]) {
            count[i] += count[j];
          }
        }
      }
    }

    int longest = 0;
    for (int l : length) longest = max(longest, l);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (length[i] == longest) ans += count[i];
    }
    return ans;
  }
};

int main(void) {
  vector<vector<int>> tests = {
    { 1, 2, 3, 4, 5 },
    { 1, 3, 5, 4, 7 },
    { 2, 2, 2, 2, 2 },
    { 5, 4, 3, 2, 1 }
  };

  for (vector<int>& nums : tests) {
    cout << Solution().findNumberOfLIS(nums) << endl;
  }
  return 0;
}
