#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;


void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int max_a = *max_element(a.begin(), a.end());

  vector<int> c(max_a+1, 1);
  c[1] = 0;
  vector<vector<int>> factors(max_a+1);
  for (int i = 2; i <= max_a; ++i) {
    for (int j = i; j <= max_a; j += i) {
      factors[j].push_back(i);
      if (j != i) {
        c[j] -= c[i];
      }
    }
  }

  vector<i64> dp(n);
  dp[0] = 1;
  vector<i64> count(max_a+1);
  for (int f : factors[a[0]]) {
    count[f] = 1;
  }

  auto mod_add = [&](i64 x, i64 y) -> i64 {
    i64 ans = x + y;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    return ans;
  };

  for (int i = 1; i < n; ++i) {
    for (int f : factors[a[i]]) {
      dp[i] = mod_add(dp[i], (count[f] * c[f]) % MOD);
    }
    for (int f : factors[a[i]]) {
      count[f] = mod_add(count[f], dp[i]);
    }
    // cout << dp[i] << endl;
    // for (int f = 2; f <= max_a; ++f) {
    //   cout << count[f] << " ";
    // }
    // cout << endl;
  }
  // cout << endl;

  cout << dp.back() << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
