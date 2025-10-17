#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1000000;
constexpr int MOD = 1e9 + 7;
// dp1[i] means number of ways to make height of i where the last block is connected
vector<i64> dp1(MAX_N+1);
// dp2[i] means number of ways to make height of i where the last block is not connected
vector<i64> dp2(MAX_N+1);

void precompute() {
  dp1[1] = 1;
  dp2[1] = 1;
  for (int i = 2; i <= MAX_N; ++i) {
    // connect the last connected block, or use a 2x1 block
    dp1[i] = dp1[i-1] * 2 + dp2[i-1];
    dp1[i] %= MOD;
    // use 2 1x1 block or 
    // connect the left block or 
    // connect the right block or
    // connect both block
    dp2[i] = dp2[i-1] * 4 + dp1[i-1];
    dp2[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  i64 ans = dp1[n] + dp2[n];
  ans %= MOD;
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
