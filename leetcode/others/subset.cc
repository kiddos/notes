#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  vector<vector<int>> subsets(vector<int>& nums, int m) {
    int n = nums.size();
    if (m == n) return {{}};

    vector<vector<int>> ans;
    vector<vector<int>> last = subsets(nums, m+1);
    for (vector<int> l : last) {
      ans.push_back(l);
      l.push_back(nums[m]);
      ans.push_back(l);
    }
    return ans;
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    return subsets(nums, 0);
  }
};

class Solution2 {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans = {{}};
    for (int n : nums) {
      vector<vector<int>> next;
      for (vector<int> o : ans) {
        o.push_back(n);
        next.push_back(o);
      }
      for (vector<int> n : next) {
        ans.push_back(n);
      }
    }
    return ans;
  }
};

class Solution3 {
 public:
  void subsets(vector<int>& nums, int start, int end,
               vector<vector<int>>& ans, vector<int>& current) {
    if (start == end) {
      ans.push_back(current);
      return;
    }

    int n = nums.size();
    for (int i = start; i < n; ++i) {
      current.push_back(nums[i]);
      subsets(nums, i+1, end, ans, current);
      current.pop_back();
    }
  }


  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    int n = nums.size();
    for (int end = 0; end <= n; ++end) {
      subsets(nums, 0, end, ans, current);
    }
    return ans;
  }
};

void output(vector<vector<int>>& ans) {
  for (auto a : ans) {
    cout << "[";
    for (int e : a) {
      cout << e << ",";
    }
    cout << "],";
  }
  cout << endl;
}


int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) nums[i] = i+1;

    auto ans = Solution1().subsets(nums);
    output(ans);

    ans = Solution2().subsets(nums);
    output(ans);

    ans = Solution3().subsets(nums);
    output(ans);
  }
  return 0;
}
