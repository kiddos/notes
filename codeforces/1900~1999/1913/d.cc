#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// p = 2 4 1 3
// [2, 4, 1, 3]
// [2, 1, 3]
// [2, 4, 1]
// [2, 1]
// [1]
// [4, 1, 3]

// p = 1 2 3 4
// [1, 2, 3, 4]
// [1, 2, 3]
// [1, 2]
// [1, 2, 4]
// [1]
// [1, 3, 4]
// [1, 4]
// [1, 3]

constexpr int MOD = 998244353;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  vector<int> s;
  vector<int> left(n, -1);
  for (int i = n-1; i >= 0; --i) {
    while (!s.empty() && p[s.back()] > p[i]) {
      left[s.back()] = i;
      s.pop_back();
    }
    s.push_back(i);
  }

  vector<i64> dp(n);
  vector<i64> ans(n);
  vector<i64> prefix(n);
  dp[0] = ans[0] = prefix[0] = 1;

  for (int i = 1; i < n; ++i) {
    int l = left[i];
    if (l < 0) {
      dp[i] = prefix[i-1] + 1;
      dp[i] %= MOD;
      ans[i] = dp[i];
    } else {
      dp[i] = (prefix[i-1] - prefix[l] + MOD) % MOD;
      dp[i] += ans[l];
      dp[i] %= MOD;
      ans[i] = dp[i] + ans[l];
      ans[i] %= MOD;
    }

    prefix[i] = dp[i];
    prefix[i] += prefix[i-1];
    prefix[i] %= MOD;
  }

  cout << ans.back() << endl;
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
