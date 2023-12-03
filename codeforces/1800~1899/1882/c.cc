#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<vector<i64>> memo(n, vector<i64>(2, -1));
  i64 ans = 0;
  function<i64(int,int)> dp = [&](int i, int odd) -> i64 {
    if (i == n) {
      return 0LL;
    }
    if (memo[i][odd] >= 0) {
      return memo[i][odd];
    }

    i64 result = 0;
    if (odd) {
      result = max(dp(i+1, odd), dp(i+1, 1-odd)) + a[i];
    } else {
      result = max(dp(i+1, odd), dp(i+1, 1-odd));
    }
    if ((i+1) % 2 == odd) {
      ans = max(ans, result);
    }
    return memo[i][odd] = result;
  };

  dp(0, 1);

  // for (int i = 0; i < n; ++i) {
  //   cout << memo[i][0] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << memo[i][1] << " ";
  // }
  // cout << endl;

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
