#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  vector<int> findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> count;
    for (int n : nums) {
      count[n]++;
    }
    vector<int> ans;
    for (auto p : count) {
      if (p.second % 2 == 0) {
        ans.push_back(p.first);
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (int n : nums) {
      nums[abs(n)-1] = -nums[abs(n)-1];
      if (nums[abs(n)-1] > 0) ans.push_back(abs(n));
    }
    return ans;
  }
};

int main(void) {
  int n = 10;
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(1, n);
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = dist(gen);
    cout << nums[i] << " ";
  }
  cout << endl;

  vector<int> ans = Solution1().findDuplicates(nums);
  sort(ans.begin(), ans.end());
  for (int a : ans) {
    cout << a << " ";
  }
  cout << endl;

  ans = Solution2().findDuplicates(nums);
  sort(ans.begin(), ans.end());
  for (int a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
