#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  constexpr int MOD = 1e9 + 7;
  int mask_size = 1<<n;
  vector<vector<int>> transition(mask_size);
  for (int i = 0; i < mask_size; ++i) {
    for (int j = 0; j < mask_size; ++j) {
      bool valid = true;
      // check if both cannot be 1
      for (int b = 0; b < n; ++b) {
        if ((i & (1<<b)) && (j & (1<<b))) {
          valid = false;
          break;
        }
      }

      // check if both are 0, the length must be even
      int b = 0;
      while (b < n) {
        if (!(i & (1<<b)) && !(j & (1<<b))) {
          int b2 = b;
          while (b2+1 < n && !(i & (1<<(b2+1))) && !(j & (1<<(b2+1)))) {
            b2++;
          }
          int len = b2-b+1;
          if (len % 2 != 0) {
            valid = false;
          }
          b = b2+1;
        } else {
          b++;
        }
      }

      if (valid) {
        transition[i].push_back(j);
      }
    }
  }

  vector<i64> dp(mask_size);
  dp[0] = 1;
  for (int i = 0; i < m; ++i) {
    vector<i64> dp2(mask_size);
    for (int mask = 0; mask < mask_size; ++mask) {
      for (int mask2 : transition[mask]) {
        dp2[mask2] += dp[mask];
        dp2[mask2] %= MOD;
      }
    }
    dp = std::move(dp2);

    // for (int mask = 0; mask < mask_size; ++mask) {
    //   cout << dp[mask] << " ";
    // }
    // cout << endl;
  }

  i64 ans = dp[0];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
