#include <bits/stdc++.h>

using namespace std;

// Maximum Earnings From Taxi
//
// my initial solution
// the basic idea is to solve it like knapsack problem

class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    map<int, long> dp;

    sort(rides.begin(), rides.end(), [&](auto& r1, auto& r2) {
      if (r1[1] == r2[1]) {
        return r1[0] < r2[0];
      }
      return r1[1] < r2[1];
    });
    for (int i = 0; i < rides.size(); ++i) {
      int start = rides[i][0], end = rides[i][1], tips = rides[i][2];
      auto p = dp.upper_bound(start);
      long prev_earn = p == dp.begin() ? 0 : prev(p)->second;
      long total = prev_earn + end - start + tips;

      auto p2 = dp.upper_bound(end);
      long last = p2 == dp.begin() ? 0 : prev(p2)->second;
      dp[end] = max({dp[end], total, last});
    }
    return prev(dp.end())->second;
  }
};

// solution without map

class Solution2 {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.rbegin(), rides.rend());

    vector<long> dp(n + 1);
    for (int i = n - 1, j = 0; i >= 1; --i) {
      dp[i] = max(dp[i], dp[i + 1]);
      while (j < rides.size() && rides[j][0] == i) {
        dp[i] = max(dp[i],
                    dp[rides[j][1]] + rides[j][1] - rides[j][0] + rides[j][2]);
        j++;
      }
    }
    return dp[1];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 5;
  vector<vector<int>> rides = {{2, 5, 4}, {1, 5, 1}};

  long ans = Solution2().maxTaxiEarnings(n, rides);
  assert(ans == 7);
  return 0;
}
