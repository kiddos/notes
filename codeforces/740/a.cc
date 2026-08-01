#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 a = 0, b = 0, c = 0;
  cin >> n >> a >> b >> c;

  constexpr i64 inf = 1e18;
  vector<i64> dp(4, inf);
  dp[n%4] = 0;
  int p = n%4;
  for (int i = p; i < p+8; ++i) {
    dp[(i+1)%4] = min(dp[(i+1)%4], dp[i%4] + a);
    dp[(i+2)%4] = min(dp[(i+2)%4], dp[i%4] + b);
    dp[(i+3)%4] = min(dp[(i+3)%4], dp[i%4] + c);
  }
  cout << dp[0] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
