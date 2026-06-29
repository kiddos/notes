#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<int> d;
  int idx = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && c[j+1] == c[j]) {
      j++;
    }
    d.push_back(c[j]);
    idx = j+1;
  }

  int size = d.size();
  vector<vector<int>> dp(size, vector<int>(size));
  for (int len = 2; len <= size; ++len) {
    for (int i = 0; i <= size-len; ++i) {
      int j = i+len-1;
      if (d[i] == d[j]) {
        dp[i][j] = dp[i+1][j-1] + 1;
      } else {
        dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
      }
    }
  }

  // for (int i = 0; i < size; ++i) {
  //   cout << d[i] << " ";
  // }
  // cout << endl;
  //
  // for (int i = 0; i < size; ++i) {
  //   for (int j = 0; j < size; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[0][size-1] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
