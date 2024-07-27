#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  int maxProfit(const vector<int>& prices) {
    int k = 2;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(k+1));
    for (int kk = 1; kk <= k; ++kk) {
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          int p = (j > 0 ? dp[j-1][kk-1] : 0);
          dp[i][kk] = max({dp[i][kk], dp[i-1][kk], prices[i] - prices[j] + p});
        }
      }
    }
    return dp[n-1][k];
  }
};

class Solution2 {
 public:
  int maxProfit(const vector<int>& prices) {
    int k = 2;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(k+1));
    for (int kk = 1; kk <= k; ++kk) {
      for (int i = 1; i < n; ++i) {
        int p = prices[0];
        for (int j = 1; j <= i; ++j) {
          p = min(p, prices[j] - dp[j-1][kk-1]);
        }
        dp[i][kk] = max(dp[i-1][kk], prices[i] - p);
      }
    }
    return dp[n-1][k];
  }
};

class Solution3 {
 public:
  int maxProfit(const vector<int>& prices) {
    int k = 2;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(k+1));
    for (int kk = 1; kk <= k; ++kk) {
      int p = prices[0];
      for (int i = 1; i < n; ++i) {
        p = min(p, prices[i] - dp[i-1][kk-1]);
        dp[i][kk] = max(dp[i-1][kk], prices[i] - p);
      }
    }
    return dp[n-1][k];
  }
};


class Solution4 {
 public:
  int maxProfit(const vector<int>& prices) {
    int k = 2;
    int n = prices.size();
    vector<int> dp(k+1);
    vector<int> p(k+1, prices[0]);
    for (int i = 1; i < n; ++i) {
      for (int kk = 1; kk <= k; ++kk) {
        p[kk] = min(p[kk], prices[i] - dp[kk-1]);
        dp[kk] = max(dp[kk], prices[i] - p[kk]);
      }
    }
    return dp[k];
  }
};


class Solution5 {
 public:
  int maxProfit(const vector<int>& prices) {
    int buy1 = numeric_limits<int>::max(), buy2 = numeric_limits<int>::max();
    int sell1 = 0, sell2 = 0;
    for (int p : prices) {
      buy1 = min(buy1, p);
      sell1 = max(sell1, p - buy1);
      buy2 = min(buy2, p - sell1);
      sell2 = max(sell2, p - buy2);
    }
    return sell2;
  }
};

int main(void) {
  constexpr int n = 1000;
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(0, n*2);
  vector<int> prices(n);
  for (int i = 0; i < n; ++i) {
    prices[i] = dist(gen);
  }

  int ans = Solution1().maxProfit(prices);
  cout << "Solution1: " << ans << endl;

  ans = Solution2().maxProfit(prices);
  cout << "Solution2: " << ans << endl;

  ans = Solution3().maxProfit(prices);
  cout << "Solution2: " << ans << endl;

  ans = Solution4().maxProfit(prices);
  cout << "Solution2: " << ans << endl;

  ans = Solution5().maxProfit(prices);
  cout << "Solution2: " << ans << endl;
  return 0;
}
