#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

constexpr int MAX_M = 200010;
vector<int> dp(MAX_M+1, 1);
void precompute() {
  for (int i = 10; i <= MAX_M; ++i) {
    dp[i] = dp[i-10] + dp[i-9];
    dp[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  int m = 0;
  cin >> n >> m;

  string s = to_string(n);
  i64 ans = 0;
  for (char ch : s) {
    int c = ch-'0';
    ans += dp[c+m];
    ans %= MOD;
  }
  cout << ans << endl;
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
