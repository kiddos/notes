#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

pair<int,int> get_delta(char ch) {
  if (ch == 'R') {
    return {0, 1};
  } else if (ch == 'L') {
    return {0, -1};
  } else if (ch == 'U') {
    return {-1, 0};
  } else {
    return {1, 0};
  }
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  auto ok = [&](int r, int c) -> bool {
    return r >= 0 && r < n && c >= 0 && c < m;
  };

  vector<vector<int>> dp(n, vector<int>(m));
  vector<vector<int>> time(n, vector<int>(m));
  int t = 0;

  for (int r0 = 0; r0 < n; ++r0) {
    for (int c0 = 0; c0 < m; ++c0) {
      if (dp[r0][c0]) {
        continue;
      }

      ++t;
      vector<pair<int,int>> path;
      int len = 0;
      int r = r0, c = c0;
      do {
        dp[r][c] = ++len;
        time[r][c] = t;
        path.emplace_back(r, c);
        auto [dr, dc] = get_delta(s[r][c]);
        r += dr;
        c += dc;
      } while (ok(r, c) && (dp[r][c] == 0));

      int start = 1;
      if (ok(r, c)) {
        if (time[r][c] == t) {
          int cycle_len = len - dp[r][c] + 1;
          for (int k = 0; k < cycle_len; ++k) {
            auto [r1, c1] = path.back();
            path.pop_back();
            dp[r1][c1] = cycle_len;
          }
        }
        start = dp[r][c] + 1;
      }

      while (!path.empty()) {
        auto [r1, c1] = path.back();
        path.pop_back();
        dp[r1][c1] = start++;
      }
    }
  }

  array<int, 3> ans = {1, 1, 0};
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (dp[r][c] > ans[2]) {
        ans = {r+1, c+1, dp[r][c]};
      }
    }
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
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
