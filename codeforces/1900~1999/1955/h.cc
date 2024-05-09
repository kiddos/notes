#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_R = 13;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  vector<int> x(k), y(k), p(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i] >> p[i];
    x[i]--;
    y[i]--;
  }

  vector<i64> p3 = {1};
  for (int i = 1; i < MAX_R; ++i) {
    p3.push_back(p3.back() * 3);
  }

  auto compute_damage = [&](int r, int c, int d, int len) -> i64 {
    int health = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '#') {
          int dx = r-i, dy = c-j;
          if (dx * dx + dy * dy <= len * len) {
            health += d;
          }
        }
      }
    }
    return health;
  };

  vector<vector<i64>> damages(k, vector<i64>(MAX_R));
  for (int i = 0; i < k; ++i) {
    for (int rad = 0; rad < MAX_R; ++rad) {
      damages[i][rad] = compute_damage(x[i], y[i], p[i], rad);
    }
  }

  int mask_size = 1 << MAX_R;
  vector<vector<i64>> dp(k+1, vector<i64>(mask_size));
  for (int i = 1; i <= k; ++i) {
    for (int mask = 0; mask < mask_size; ++mask) {
      dp[i][mask] = dp[i-1][mask];
      for (int rad = 0; rad < MAX_R; ++rad) if (mask & (1<<rad)) {
        dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1<<rad)] + damages[i-1][rad]);
      }
    }
  }

  i64 ans = 0;
  for (int mask = 1; mask < mask_size; ++mask) {
    i64 power3 = 0;
    for (int rad = 0; rad < MAX_R; ++rad) if (mask & (1<<rad)) {
      power3 += p3[rad];
    }
    ans = max(ans, dp[k][mask] - power3);
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
