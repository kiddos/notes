#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution1(vector<int> nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0 && nums[i] == nums[i-1]) continue;
    int a = nums[i];
    for (int j = i+1; j < n; ++j) {
      if (j > i+1 && nums[j] == nums[j-1]) continue;
      int b = nums[j];
      int target = -a-b;
      int l = j+1, r = n-1;
      while (l <= r) {
        int m = l+(r-l)/2;
        if (nums[m] == target) {
          ans.push_back({a, b, nums[m]});
          break;
        } else if (nums[m] < target) {
          l = m+1;
        } else {
          r = m-1;
        }
      }
    }
  }
  return ans;
}

vector<vector<int>> solution2(vector<int> nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<vector<int>> ans;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && nums[i] == nums[i-1]) continue;
    int a = nums[i];
    int begin = i+1, end = n-1;
    while (begin < end) {
      int sum = nums[begin] + nums[end];
      if (sum < -a) {
        begin++;
      } else if (sum > -a) {
        end--;
      } else {
        int b = nums[begin], c = nums[end];
        ans.push_back({a, b, c});
        while (begin < end && nums[begin] == b) begin++;
        while (end > begin && nums[end] == c) end--;
      }
    }
  }
  return ans;
}


int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    auto ans1 = solution1(nums);
    for (auto tri : ans1) {
      cout << tri[0] << ", " << tri[1] << ", " << tri[2] << endl;
    }

    auto ans2 = solution2(nums);
    for (auto tri : ans2) {
      cout << tri[0] << ", " << tri[1] << ", " << tri[2] << endl;
    }

    cout << endl;
  }
  return 0;
}
