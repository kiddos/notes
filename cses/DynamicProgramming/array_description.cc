#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  constexpr int MOD = 1e9 + 7;
  vector<i64> dp(m+1);
  if (x[0] == 0) {
    for (int i = 1; i <= m; ++i) {
      dp[i] = 1;
    }
  } else {
    dp[x[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    vector<i64> dp2(m+1);
    if (x[i] == 0) {
      for (int y = 1; y <= m; ++y) {
        for (int z = max(y-1, 1); z <= min(y+1, m); ++z) {
          dp2[y] += dp[z];
          dp2[y] %= MOD;
        }
      }
    } else {
      for (int z = max(x[i]-1, 1); z <= min(x[i]+1, m); ++z) {
        dp2[x[i]] += dp[z];
        dp2[x[i]] %= MOD;
      }
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  if (x.back() > 0) {
    ans = dp[x.back()];
  } else {
    for (int y = 1; y <= m; ++y) {
      ans += dp[y];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
