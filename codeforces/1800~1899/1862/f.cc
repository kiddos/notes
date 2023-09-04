#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 w = 0, f = 0;
  cin >> w >> f;
  int n = 0;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  i64 sum = accumulate(s.begin(), s.end(), 0);
  vector<bool> dp(sum+1);
  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int a = sum; a >= 0; --a) {
      if (dp[a] && a+s[i] <= sum) {
        dp[a+s[i]] = true;
      }
    }
  }

  int ans = numeric_limits<int>::max();
  for (int a = 0; a <= sum; ++a) {
    if (dp[a]) {
      int group1 = a;
      int group2 = sum - a;
      
      int water = (group1 + w - 1) / w;
      int fire = (group2 + f - 1) / f;
      int require = max(water, fire);
      ans = min(ans, require);

      water = (group2 + w - 1) / w;
      fire = (group1 + f - 1) / f;
      require = max(water, fire);
      ans = min(ans, require);
    }
  }

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
