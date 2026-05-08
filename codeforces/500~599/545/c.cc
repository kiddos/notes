#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n), h(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> h[i];
  }

  vector<int> x0 = x;

  set<int> s;
  vector<pair<int,int>> trees;
  for (int i = 0; i < n; ++i) {
    trees.push_back({x[i], h[i]});
  }
  sort(trees.begin(), trees.end());
  sort(x0.begin(), x0.end());
  auto has_tree = [&](int l, int r) -> bool {
    auto it = lower_bound(x0.begin(), x0.end(), l);
    return it != x0.end() && *it <= r;
  };

  map<int,int> dp;

  auto update_max = [&](int xi) {
    auto it = dp.upper_bound(xi-1);
    if (it != dp.begin()) {
      --it;
      dp[xi] = max(dp[xi], it->second);
    }
  };

  for (int i = 0; i < n; ++i) {
    auto [xi, hi] = trees[i];

    if (!has_tree(xi-hi, xi-1)) {
      auto it = dp.upper_bound(xi-hi-1);
      if (it != dp.begin()) {
        --it;
        dp[xi] = max(dp[xi], it->second + 1);
      } else {
        dp[xi] = max(dp[xi], 1);
      }
      update_max(xi);
    }
    if (!has_tree(xi+1, xi+hi)) {
      auto it = dp.upper_bound(xi-1);
      if (it != dp.begin()) {
        --it;
        dp[xi+hi] = max(dp[xi+hi], it->second + 1);
      } else {
        dp[xi+hi] = max(dp[xi+hi], 1);
      }
      update_max(xi+hi);
    }
  }

  int ans = 0;
  for (auto [p, count] : dp) {
    ans = max(ans, count);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
