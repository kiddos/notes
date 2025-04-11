#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_P = 61;
constexpr i64 INF = 3e18;
vector<vector<vector<i64>>> dp(MAX_P, vector<vector<i64>>(MAX_P, vector<i64>(MAX_P, INF)));

void precompute() {
  dp[0][0][0] = 0;
  for (int i = 1; i < MAX_P; ++i) {
    for (int x = MAX_P-1; x >= 0; --x) {
      for (int y = MAX_P-1; y >= 0; --y) {
        dp[i][x][y] = min(dp[i][x][y], dp[i-1][x][y]);
        
        if (dp[i][x][y] >= INF) {
          continue;
        }

        i64 cost = 1LL << i;
        if (x+i < MAX_P) {
          dp[i][x+i][y] = min(dp[i][x+i][y], dp[i][x][y] + cost);
        }
        if (y+i < MAX_P) {
          dp[i][x][y+i] = min(dp[i][x][y+i], dp[i][x][y] + cost);
        }
      }
    }
  }
}

void solve() {
  i64 x = 0, y = 0;
  cin >> x >> y;
  i64 ans = INF;
  for (i64 a = 0; a < MAX_P; ++a) {
    for (i64 b = 0; b < MAX_P; ++b) {
      if ((x >> a) == (y >> b)) {
        ans = min(ans, dp[MAX_P-1][a][b]);
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
