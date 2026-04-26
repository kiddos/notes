#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> dp(360);
  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    vector<bool> dp2(360);
    for (int d = 0; d < 360; ++d) {
      if (!dp[d]) {
        continue;
      }
      int d2 = (d + a[i]) % 360;
      dp2[d2] = true;
      int d3 = (d - a[i] + 360) % 360;
      dp2[d3] = true;
    }
    dp = std::move(dp2);
  }

  if (dp[0]) {
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
