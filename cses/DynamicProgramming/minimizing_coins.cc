#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  constexpr i64 inf = 1e18;
  vector<i64> dp(x+1, inf);
  dp[0] = 0;
  for (int val = 0; val < x; ++val) {
    for (int i = 0; i < n; ++i) {
      if (val+c[i] <= x) {
        dp[val+c[i]] = min(dp[val+c[i]], dp[val]+1);
      }
    }
  }
  if (dp[x] >= inf) {
    cout << "-1" << endl;
  } else {
    cout << dp[x] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
