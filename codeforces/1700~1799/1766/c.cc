#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> c(2);
  cin >> c[0] >> c[1];

  int black = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      black += c[i][j] == 'B';
    }
  }

  bool ans = false;
  vector<int> dp(2);
  for (int j = 1; j <= n; ++j) {
    vector<int> next_dp(2);
    for (int i = 0; i < 2; ++i) {
      if (c[i][j-1] == 'B') {
        int i2 = 1-i;
        if (c[i2][j-1] == 'B') {
          next_dp[i] = dp[i2] + 2;
        } else {
          next_dp[i] = dp[i] + 1;
        }
      }

      if (next_dp[i] == black) {
        ans = true;
        break;
      }
    }
    dp = move(next_dp);
  }

  // for (int i = 0; i < 2; ++i) {
  //   for (int j = 0; j <= n; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
