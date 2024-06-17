#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int MOD = 998244353;
  map<i64, i64> dp;
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    map<i64, i64> dp2;
    auto smallest = *dp.begin();
    auto largest = *dp.rbegin();

    dp2[smallest.first + a[i]] += smallest.second;
    dp2[smallest.first + a[i]] %= MOD;
    dp2[abs(smallest.first + a[i])] += smallest.second;
    dp2[abs(smallest.first + a[i])] %= MOD;
    if (largest != smallest) {
      dp2[largest.first + a[i]] += largest.second;
      dp2[largest.first + a[i]] %= MOD;
      dp2[abs(largest.first + a[i])] += largest.second;
      dp2[abs(largest.first + a[i])] %= MOD;
    }
    dp = std::move(dp2);
  }
  cout << dp.rbegin()->second << endl;
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
