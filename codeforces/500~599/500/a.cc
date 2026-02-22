#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
  vector<int> a(n+1);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> dp(n+1);
  dp[t] = true;
  for (int i = t-1; i >= 1; --i) {
    if (i + a[i] <= n) {
      dp[i] = dp[i+a[i]];
    }
  }
  if (dp[1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
