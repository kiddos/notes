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

  int max_end = 0;
  for (int i = 1; i < n; ++i) {
    max_end += a[i];
  }
  int min_end = -max_end;
  int size = max_end - min_end + 1;
  // cout << "min=" << min_end << ",max=" << max_end << endl;
  int offset = min_end;
  vector<i64> dp(size);
  dp[a[1] - offset] = 1;

  // map<int,i64> dp3;
  // dp3[a[1]] = 1;

  constexpr int MOD = 998244353;
  for (int i = 2; i < n; ++i) {
    vector<i64> dp2(size);
    for (int x_prime = 0; x_prime < size; ++x_prime) {
      if (dp[x_prime] == 0) {
        continue;
      }

      int x = x_prime + offset;
      if (x == 0) {
        if (a[i] - offset >= 0 && a[i] - offset < size) {
          dp2[a[i] - offset] += dp[x_prime];
          dp2[a[i] - offset] %= MOD;
        }
      } else {
        if (a[i] + x - offset >= 0 && a[i] + x - offset < size) {
          dp2[a[i] + x - offset] += dp[x_prime];
          dp2[a[i] + x - offset] %= MOD;
        }
        if (a[i] - x - offset >= 0 && a[i] - x - offset < size) {
          dp2[a[i] - x - offset] += dp[x_prime];
          dp2[a[i] - x - offset] %= MOD;
        }
      }
    }
    dp = std::move(dp2);
    // for (int j = 0; j < size; ++j) {
    //   cout<< dp[j] << " ";
    // }
    // cout << endl;

    // map<int,i64> dp4;
    // for (auto& [x, count] : dp3) {
    //   if (x == 0) {
    //     dp4[a[i]] += count;
    //     dp4[a[i]] %= MOD;
    //   } else {
    //     dp4[a[i] + x] += count;
    //     dp4[a[i] - x] += count;
    //     dp4[a[i] + x] %= MOD;
    //     dp4[a[i] - x] %= MOD;
    //   }
    // }
    // dp3 = std::move(dp4);
  }

  i64 ans = 0;
  for (int x_prime = 0; x_prime < size; ++x_prime) {
    ans += dp[x_prime];
    ans %= MOD;
  }
  cout << ans << endl;

  // i64 ans2 = 0;
  // for (auto [x, count] : dp3) {
  //   ans2 += count;
  //   ans2 %= MOD;
  // }
  // cout << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
