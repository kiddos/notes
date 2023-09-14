#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 40000;
constexpr int MOD = 1e9 + 7;

bool is_palindromic(int x) {
  string s = to_string(x);
  return s == string(s.rbegin(), s.rend());
}

vector<int> palindromes;
vector<vector<i64>> dp;

void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    if (is_palindromic(i)) {
      palindromes.push_back(i);
    }
  }

  int m = palindromes.size();
  // function<i64(int,int)> dp = [&](int sum, int i) -> i64 {
  //   if (sum < 0) {
  //     return 0;
  //   }
  //   if (i == m) {
  //     return sum == 0 ? 1 : 0;
  //   }
  //   i64 ans = dp(sum - palindromes[i], i) + dp(sum, i+1);
  //   return memo[sum][i] = ans;
  // };

  dp = vector<vector<i64>>(MAX_N+1, vector<i64>(m+1));
  dp[0][0] = 1;
  for (int n = 0; n <= MAX_N; ++n) {
    for (int i = 1; i <= m; ++i) {
      dp[n][i] += dp[n][i-1];
      dp[n][i] %= MOD;
      int p = palindromes[i-1];
      if (n - p >= 0) {
        dp[n][i] += dp[n-p][i];
        dp[n][i] %= MOD;
      }
    }
  }

  // for (int i = 0; i <= MAX_N; ++i) {
  //   cout << dp[i][m] << " ";
  // }
  // cout << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  int m = palindromes.size();
  cout << dp[n][m] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
