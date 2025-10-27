#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<pair<int,int>> movies;
  for (int i = 0; i < n; ++i) {
    movies.emplace_back(b[i], a[i]);
  }
  sort(movies.begin(), movies.end());

  map<int,int> dp;
  int ans = 0;
  for (auto [end_t, start_t] : movies) {
    dp[end_t] = max(dp[end_t], 1);
    auto it = dp.upper_bound(start_t);
    if (it != dp.begin()) {
      --it;
      dp[end_t] = max(dp[end_t], it->second + 1);
    }

    it = dp.upper_bound(end_t-1);
    if (it != dp.begin()) {
      --it;
      dp[end_t] = max(dp[end_t], it->second);
    }
    ans = max(ans, dp[end_t]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
