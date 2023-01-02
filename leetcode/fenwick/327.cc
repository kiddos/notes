#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
 public:
  FenwickTree(int n) : fenwick_(n+1) {}

  void update(int i, int delta) {
    int n = fenwick_.size();
    while (i < n) {
      fenwick_[i] += delta;
      i += (i & -i);
    }
  }

  int get(int i) {
    int ans = 0;
    while (i > 0) {
      ans += fenwick_[i];
      i -= (i & -i);
    }
    return ans;
  }

  int query(int lower, int upper) { return get(upper) - get(lower-1);
  }

 private:
  vector<int> fenwick_;
};

class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    set<long long> s({0, upper, lower});
    long long sum = 0;
    for (int num : nums) {
      sum += num;
      s.insert(sum);
      s.insert(sum + lower);
      s.insert(sum + upper);
    }

    vector<long long> sums(s.begin(), s.end());
    unordered_map<long long, int> index;
    int m = sums.size();
    for (int i = 0; i < m; ++i) {
      index[sums[i]] = i+1;
    }

    int ans = 0;
    FenwickTree fenwick(sums.size()+1);
    int n = nums.size();
    for (int i = n-1; i >= 0; --i) {
      fenwick.update(index[sum], 1);
      sum -= nums[i];
      ans += fenwick.query(index[sum+lower], index[sum+upper]);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums;
  int lower, upper;
  int ans;
  nums = {-2, 5, -1};
  lower = -2, upper = 2;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 3);

  nums = {-2147483647, 0, -2147483647, 2147483647};
  lower = -564, upper = 3864;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 3);

  nums = { 2147483647,-2147483648,-1,0 };
  lower = -1, upper = 0;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 4);

  nums = { -2,-1,-2,-1,-3,-2 };
  lower = 1, upper = 6;
  ans = Solution().countRangeSum(nums, lower, upper);
  assert(ans == 0);
  return 0;
}
