#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;
    for (int n : nums) {
      if (candidate1 == n) count1++;
      else if (candidate2 == n) count2++;
      else if (count1 == 0) {
        candidate1 = n;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = n;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }

    count1 = 0;
    count2 = 0;
    for (int n : nums) {
      count1 += (n == candidate1);
      count2 += (n == candidate2);
    }
    vector<int> ans;
    if (count1 > nums.size() / 3) ans.push_back(candidate1);
    if (count2 > nums.size() / 3 && candidate2 != candidate1) ans.push_back(candidate2);
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }

    vector<int> ans = Solution().majorityElement(nums);
    cout << "ans : " << endl;
    for (int a : ans) cout << a << " ";
    cout << endl;
  }
  return 0;
}
