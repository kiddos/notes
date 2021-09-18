#include <bits/stdc++.h>

using namespace std;

// Cheapest Flights Within K Stops
//
// bellman-ford solution
// this can also be done using dijkstra

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<int> dp(n, numeric_limits<int>::max());
    dp[src] = 0;
    for (int t = 0; t <= k; ++t) {
      vector<int> next_dp = dp;
      for (vector<int>& f : flights) {
        int u = f[0], v = f[1], price = f[2];
        if (dp[u] != numeric_limits<int>::max()) {
          next_dp[v] = min(next_dp[v], dp[u] + price);
        }
      }
      dp = move(next_dp);
    }
    if (dp[dst] == numeric_limits<int>::max()) return -1;
    return dp[dst];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 5;
  vector<vector<int>> flights = {{0, 1, 5}, {1, 2, 5}, {0, 3, 2},
                                 {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
  int src = 0;
  int dst = 2;
  int k = 2;

  int ans = Solution().findCheapestPrice(n, flights, src, dst, k);
  assert(ans == 7);

  return 0;
}
