#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_P = 200;

int dp[MAX_P+1][MAX_P+1][MAX_P+1];

void precompute() {
  for (int a = 0; a <= MAX_P; ++a) {
    for (int b = 0; b <= MAX_P; ++b) {
      for (int c = 0; c <= MAX_P; ++c) {
        int x = (a % 2 == 1 ? 1 : 0) ^ (b % 2 == 1 ? 2 : 0)  ^ (c % 2 == 1 ? 3 : 0);
        int add = x == 0 ? 1 : 0;
        if (a == 0 && b == 0 && c == 0) {
          dp[a][b][c] = 0;
        } else {
          dp[a][b][c] = add;
        }
        if (a > 0) {
          dp[a][b][c] = max(dp[a][b][c], dp[a-1][b][c] + add);
        }
        if (b > 0) {
          dp[a][b][c] = max(dp[a][b][c], dp[a][b-1][c] + add);
        }
        if (c > 0) {
          dp[a][b][c] = max(dp[a][b][c], dp[a][b][c-1] + add);
        }
      }
    }
  }
}

void solve() {
  vector<int> p(5);
  for (int i = 1; i <= 4; ++i) cin >> p[i];

  int ans = dp[p[1]][p[2]][p[3]] + p[4] / 2;
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
