#include <bits/stdc++.h>
 
using namespace std;
 
struct Coin {
  int op;
  int coins;
};
 
int solve(vector<int>& ops, vector<int>& b, vector<int>& c, int k) {
  int n = b.size();
  vector<Coin> coins;
  for (int i = 0; i < n; ++i) {
    coins.push_back(Coin{ops[b[i]], c[i]});
  }
 
  int ans = 0;
  unordered_map<int, int> dp;
  dp[0] = 0;
  for (auto coin : coins) {
    unordered_map<int, int> next_dp = dp;
    for (auto d : dp) {
      int ops = d.first + coin.op;
      if (ops <= k) {
        int more_coins = d.second + coin.coins;
        next_dp[ops] = max(next_dp[ops], more_coins);
        ans = max(ans, more_coins);
      }
    }
    dp = move(next_dp);
  }
  return ans;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  vector<int> dp(1001, numeric_limits<int>::max());
  dp[0] = dp[1] = 0;
  for (int i = 1; i <= 1000; ++i) {
    for (int x = i; x >= 1; --x) {
      int next_i = i + i / x;
      if (next_i <= 1000) {
        dp[next_i] = min(dp[next_i], dp[i]+1);
      }
    }
  }
 
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
 
    vector<int> b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
 
    int ans = solve(dp, b, c, k);
    cout << ans << endl;
  }
  return 0;
}
