#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,3>> projects;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0, p = 0;
    cin >> a >> b >> p;
    projects.push_back({a, b, p});
  }
  sort(projects.begin(), projects.end(), [&](auto& p1, auto& p2) {
    return p1[1] < p2[1];
  });

  i64 ans = 0;
  map<int, i64> dp;
  for (int i = 0; i < n; ++i) {
    auto [a, b, p] = projects[i];
    dp[b] = max(dp[b], (i64)p);

    auto it = dp.upper_bound(a-1);
    if (it != dp.begin()) {
      --it;
      dp[b] = max(dp[b], it->second + p);
    }
    it = dp.upper_bound(b-1);
    if (it != dp.begin()) {
      --it;
      dp[b] = max(dp[b], it->second);
    }
    ans = max(ans, dp[b]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
