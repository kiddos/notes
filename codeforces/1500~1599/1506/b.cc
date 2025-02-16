#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> index;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      index.push_back(i);
    }
  }

  constexpr int inf = 1e9;
  int m = index.size();
  vector<int> dp(m, inf);
  dp[0] = 1;
  for (int i = 1; i < m; ++i) {
    for (int j = i-1; j >= 0 && index[i] - index[j] <= k; --j) {
      dp[i] = min(dp[i], dp[j] + 1);
    }
  }

  cout << dp.back() << endl;
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
