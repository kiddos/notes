#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  constexpr int inf = 1e9;
  vector<int> dp(n+1, inf);
  dp[n] = 0;
  for (int x = n; x > 0; --x) {
    int y = x;
    while (y > 0) {
      int d = y % 10;
      if (d > 0 && x-d >= 0) {
        dp[x-d] = min(dp[x-d], dp[x] + 1);
      }
      y /= 10;
    }
  }
  if (dp[0] >= inf) {
    cout << "-1" << endl;
  } else {
    cout << dp[0] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
