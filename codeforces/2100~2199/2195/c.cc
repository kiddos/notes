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

  vector<vector<int>> adj = {
    {},
    {2, 3, 4, 5}, // 1
    {1, 3, 4, 6}, // 2
    {1, 2, 5, 6}, // 3
    {1, 2, 5, 6}, // 4
    {1, 3, 4, 6}, // 5
    {2, 3, 4, 5}, // 6
  };

  vector<vector<int>> memo(n, vector<int>(7, -1));
  auto dp = [&](const auto& self, int i, int val) -> int {
    int add = a[i] != val ? 1 : 0;
    if (i == n-1) {
      return add;
    }
    if (memo[i][val] >= 0) {
      return memo[i][val];
    }
    int ans = numeric_limits<int>::max();
    for (int val2 : adj[val]) {
      ans = min(ans, self(self, i+1, val2) + add);
    }
    return memo[i][val] = ans;
  };

  int ans = numeric_limits<int>::max();
  for (int val = 1; val <= 6; ++val) {
    ans = min(ans, dp(dp, 0, val));
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
