#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, ax = 0, ay = 0, bx = 0, by = 0;
  cin >> n >> ax >> ay >> bx >> by;
  vector<i64> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> y[i];
  }
  map<i64,vector<i64>> by_x;
  for (int i = 0; i < n; ++i) {
    by_x[x[i]].push_back(y[i]);
  }
  by_x[ax].push_back(ay);
  by_x[bx].push_back(by);
  vector<array<i64,3>> positions;
  for (auto [xi, ys] : by_x) {
    i64 max_y = *max_element(ys.begin(), ys.end());
    i64 min_y = *min_element(ys.begin(), ys.end());
    positions.push_back({xi, min_y, max_y});
  }

  int size = positions.size();
  vector<vector<i64>> memo(size, vector<i64>(2, -1));
  auto dp = [&](const auto& self, int i, int top) -> i64 {
    if (i >= size-1) {
      return 0;
    }
    if (memo[i][top] >= 0) {
      return memo[i][top];
    }
    auto [xi, min_y1, max_y1] = positions[i];
    auto [xj, min_y2, max_y2] = positions[i+1];
    i64 y_dist = max_y1 - min_y1;
    i64 x_dist = xj - xi;
    i64 dist = y_dist + x_dist;
    i64 ans = 0;
    if (top) {
      ans = min(dist + abs(min_y1 - max_y2) + self(self, i+1, 1),
                dist + abs(min_y1 - min_y2) + self(self, i+1, 0));
    } else {
      ans = min(dist + abs(max_y1 - max_y2) + self(self, i+1, 1),
                dist + abs(max_y1 - min_y2) + self(self, i+1, 0));
    }
    return memo[i][top] = ans;
  };

  i64 ans = dp(dp, 0, 0);
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
