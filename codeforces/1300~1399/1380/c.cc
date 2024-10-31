#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  vector<int> dp(n+1);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      dp[i] = max(dp[i], dp[i-1]);
    }

    int member = (x + a[i] - 1) / a[i];
    if (i+member <= n) {
      dp[i+member] = max(dp[i+member], dp[i] +1);
    }
  }
  cout << dp[n] << endl;
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
