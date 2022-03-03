#include <bits/stdc++.h>

using namespace std;

// Number of Ways to Separate Numbers
//
// this one is super hard for me.
// I am only able to come up with O(n^4) solution below
// the solution requires O(n^2)
//
// so the DP is as follow
// dp[i][j] = number of possilibity for substring num[i...j]
// so the final answer is dp[0][n-1] + dp[1][n-1] + ... + dp[n-1][n-1]
//
// base case:
// dp[0][0] = dp[0][1] = dp[0][2] = ... = dp[0][n-1] = 1
//
// dp[i][j] = sum(dp[k][i-1] for k <= i-1 if num[k...i-1] is less than
// num[i...j]) this requires O(n^2)
// => O(n) to compare num[k...i-1] with num[i...j] for k <= i-1 O(n)
//
// Need to do some precomputation:
// 1. compute longest common prefix
//  this is useful for comparing num[k...i-1] with num[i...j]
//  if we get the longest prefix for num[k...i-1] and num[i...j]
//  we can compare the 2 substring in O(1)
//  by comparing the first character that is different
//
// 2. the second trick is to pivot i, while moving j++, and k-- and compute
// dp[i][j]
//  this will only take O(n^2)
//
// dp transition:
//
// for i in 1...n-1
//  prefix_sum = 0
//  for j from (i...n-1), k from i-1
//    dp[i][j] = prefix_sum
//    if num[k...i-1] < num[i...j]
//      dp[i][j] += dp[k][i-1]
//    prefix_sum += dp[k][i-1]
//
//
// so a different way to do DP
// is to think of dp2[i][j] = dp[0][j] + dp[1][j] + ... + dp[i][j]
//
// dp transition:
// for i in 1...n-1
//  if num[i] == '0'
//    dp2[i] = dp[i-1]
//  else
//    for j in i...n-1
//      len = j-i+1
//      k = i-len
//      if k < 0
//        dp2[i][j] = dp2[i-1][j] + dp2[i-1][i-1]
//        # dp[0][j] + dp[1][j] + ... + dp[i][j] =
//        # dp[0][j] + dp[1][j] + ... + dp[i-1][j] +
//        # dp[0][i-1] + dp[1][i-1] + ... + dp[i-1][i-1]
//      else
//        if num[i...j] > num[k...i-1]
//          sum = dp2[i-1][i-1] - dp2[k-1][i-1]
//          # sum = dp[k][i-1] + dp[k+1][i-1] + ... + dp[i-1][i-1]
//          dp2[i][j] = dp2[i-1][j] + sum
//        else
//          sum = dp2[i-1][i-1] - dp2[k][i-1]
//          # not include dp[k][i-1] here
//          # sum = dp[k+1][i-1] + dp[k+2][i-1] + ... + dp[i-1][i-1]
//          dp2[i][j] = dp2[i-1][j] + sum

typedef long long ll;

class TLESolution {
 public:
  int numberOfCombinations(string num) {
    function<bool(int, int, int, int)> ge = [&](int i1, int j1, int i2,
                                                int j2) {
      int len1 = j1 - i1 + 1;
      int len2 = j2 - i2 + 1;
      if (i2 < 0) return true;
      if (len1 == len2) {
        for (int k = 0; k < len1; ++k) {
          if (num[i1 + k] > num[i2 + k]) return true;
          if (num[i1 + k] < num[i2 + k]) return false;
        }
        return true;
      }
      return len1 > len2;
    };

    const int MOD = 1e9 + 7;
    int n = num.length();
    vector<unordered_map<int, ll>> memo(n);
    function<ll(int, int)> dp = [&](int start, int last) {
      if (start == n) return 1LL;
      if (num[start] == '0') return 0LL;
      if (memo[start].count(last)) return memo[start][last];
      ll ans = 0;
      for (int i = start; i < n; ++i) {
        if (ge(start, i, last, start - 1)) {
          ans += dp(i + 1, start);
          ans = ans % MOD;
        }
      }
      return memo[start][last] = ans;
    };
    return dp(0, -1);
  }
};

class Solution {
 public:
  int numberOfCombinations(string num) {
    if (num[0] == '0') return 0;

    const int MOD = 1e9 + 7;
    int n = num.length();
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (num[i] == num[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }

    auto ge = [&](int i, int j, int k) {
      int len = j - i + 1;
      int prefix = lcp[k][i];
      return prefix >= len || num[k + prefix] < num[i + prefix];
    };

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int j = 0; j < n; ++j) dp[0][j] = 1;

    for (int i = 1; i < n; ++i) {
      if (num[i] == '0') continue;
      ll sum = 0;
      for (int j = i, k = i - 1; j < n; ++j, --k) {
        dp[i][j] = sum;
        if (k < 0) continue;
        if (num[k] > '0' && ge(i, j, k)) {
          dp[i][j] += dp[k][i - 1];
          dp[i][j] %= MOD;
        }
        sum += dp[k][i - 1];
        sum %= MOD;
      }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += dp[i][n - 1];
      ans %= MOD;
    }
    return ans;
  }
};

class Solution2 {
 public:
  int numberOfCombinations(string num) {
    if (num[0] == '0') return 0;

    const int MOD = 1e9 + 7;
    int n = num.length();
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (num[i] == num[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }

    auto ge = [&](int i, int j, int k) {
      int len = j - i + 1;
      int prefix = lcp[k][i];
      return prefix >= len || num[k + prefix] < num[i + prefix];
    };

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int j = 0; j < n; ++j) dp[0][j] = 1;

    for (int i = 1; i < n; ++i) {
      if (num[i] == '0') {
        dp[i] = dp[i - 1];
        continue;
      }

      for (int j = i; j < n; ++j) {
        int len = j - i + 1;
        int k = i - len;
        if (k < 0) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][i - 1];
          dp[i][j] %= MOD;
        } else {
          if (ge(i, j, k)) {
            ll sum = dp[i - 1][i - 1] - (k > 0 ? dp[k - 1][i - 1] : 0);
            sum = (sum + MOD) % MOD;
            dp[i][j] = dp[i - 1][j] + sum;
            dp[i][j] %= MOD;
          } else {
            ll sum = dp[i - 1][i - 1] - dp[k][i - 1];
            sum = (sum + MOD) % MOD;
            dp[i][j] = dp[i - 1][j] + sum;
            dp[i][j] %= MOD;
          }
        }
      }
    }
    return dp[n - 1][n - 1];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string num = "327";
  int ans = Solution().numberOfCombinations(num);
  assert(ans == 2);
  ans = Solution2().numberOfCombinations(num);
  assert(ans == 2);

  num = "094";
  ans = Solution().numberOfCombinations(num);
  assert(ans == 0);
  ans = Solution2().numberOfCombinations(num);
  assert(ans == 0);

  num = "0";
  ans = Solution().numberOfCombinations(num);
  assert(ans == 0);
  ans = Solution2().numberOfCombinations(num);
  assert(ans == 0);

  num = "12093810923";
  ans = Solution().numberOfCombinations(num);
  assert(ans == 12);
  ans = Solution2().numberOfCombinations(num);
  assert(ans == 12);

  num = "394801234";
  ans = Solution().numberOfCombinations(num);
  assert(ans == 8);
  ans = Solution2().numberOfCombinations(num);
  assert(ans == 8);
  return 0;
}
