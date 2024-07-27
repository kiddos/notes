#include <bits/stdc++.h>

using namespace std;

// DP
class Solution1 {
 public:
  int split(vector<int>& prefix_sum, int end, int m) {
    if (m == 1) {
      return prefix_sum[end];
    } else {
      if (memo_[end][m]) return memo_[end][m];
      long ans = numeric_limits<int>::max();
      for (int k = 0; k < end; ++k) {
        long max_val = max(split(prefix_sum, k, m-1), prefix_sum[end] - prefix_sum[k]);
        ans = min(ans, max_val);
      }
      memo_[end][m] = ans;
      return ans;
    }
  }

  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<int> prefix_sum(n+1);
    for (int i = 1; i <= n; ++i) prefix_sum[i] = prefix_sum[i-1] + nums[i-1];

    memo_ = vector<vector<int>>(n+1, vector<int>(m+1));
    return split(prefix_sum, n, m);
  }

private:
  vector<vector<int>> memo_;
};

class Solution2 {
 public:
  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<long> prefix_sum(n+1);
    for (int i = 1; i <= n; ++i) {
      prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
    }

    vector<vector<long>> dp(m+1, vector<long>(n+1, numeric_limits<int>::max()));
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = i-1; k < j; ++k) {
          long max_val = max(dp[i-1][k], prefix_sum[j] - prefix_sum[k]);
          dp[i][j] = min(dp[i][j], max_val);
        }
      }
    }
    return dp[m][n];
  }
};

class Solution3 {
 public:
  int splitArray(vector<int>& nums, int m) {
    int low = numeric_limits<int>::min(), high = 0;
    for (int n : nums) {
      low = max(low, n);
      high += n;
    }

    int ans = numeric_limits<int>::max();
    int l = low, r = high;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (canpartition(nums, m, mid)) {
        r = mid-1;
        ans = min(ans, mid);
      } else {
        l = mid+1;
      }
    }
    return ans;
  }

  bool canpartition(vector<int>& nums, int m, int current_sum) {
    int sum = 0;
    int partition = 1;
    for (int n : nums) {
      sum += n;
      if (sum > current_sum) {
        partition++;
        sum = n;
      }
      if (partition > m) return false;
    }
    return true;
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
    int m = 0;
    cin >> m;

    int ans = Solution1().splitArray(nums, m);
    cout << "ans = " << ans << endl;

    ans = Solution2().splitArray(nums, m);
    cout << "ans = " << ans << endl;

    ans = Solution3().splitArray(nums, m);
    cout << "ans = " << ans << endl;
  }
  return 0;
}
