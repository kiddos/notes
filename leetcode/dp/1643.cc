#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string kthSmallestPath(const vector<int>& destination, int k) {
    int n = destination[0] + destination[1];
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = dp[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
      }
    }

    string ans;
    int down = destination[0];
    for (int i = 1; i <= n; ++i) {
      int combination = dp[n-i][down];
      if (combination >= k) {
        ans.push_back('H');
      } else {
        ans.push_back('V');
        down--;
        k -= combination;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string ans = Solution().kthSmallestPath({15, 15}, 155117520);
  assert(ans == "VVVVVVVVVVVVVVVHHHHHHHHHHHHHHH");

  // code here...
  return 0;
}
