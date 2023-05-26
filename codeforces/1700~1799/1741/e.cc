#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<bool> dp(n+1);
  dp[0] = true;
  for (int i = 1; i <= n; ++i) {
    if (i-a[i]-1 >= 0 && dp[i-a[i]-1]) {
      dp[i] = true;
    }
    if (dp[i-1]) {
      if (i+a[i] <= n) dp[i+a[i]] = true;
    }
  }

  if (dp[n]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
