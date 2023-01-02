#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
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
