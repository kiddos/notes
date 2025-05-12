#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;

  vector<i64> dp(n+1);
  for (int i = 1; i <= n; ++i) {
    i64 x = n / i;
    dp[i] = (x - 1) * x / 2;
  }
  for (int i = n; i >= 1; --i) {
    for (int j = i+i; j <= n; j += i) {
      dp[i] -= dp[j];
    }
  }

  i64 ans = 0;
  for (int k1 = n; k1 >= 2; --k1) {
    i64 edge_count = dp[k1];
    i64 k = k1-1;
    i64 cost = k1;
    i64 pack = min(edge_count, m) / k;
    m -= pack * k;
    ans += cost * pack;
    // cout << "k=" << k << ", edge_count=" << edge_count << endl;
  }

  // cout << "m=" << m << endl;
  if (m == 0) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
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
