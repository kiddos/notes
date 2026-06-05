#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int incorrect_dp(vector<vector<int>>& a) {
  int n = a.size(), m = a[0].size();
  vector<vector<int>> dp(n+1, vector<int>(m+1));
  dp[0][1] = a[0][0];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = max(dp[i-1][j] & a[i-1][j-1], dp[i][j-1] & a[i-1][j-1]);
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return dp[n][m];
}

int correct(vector<vector<int>>& a) {
  int n = a.size(), m = a[0].size();
  int ans = 0;
  for (int b = 30; b >= 0; --b) {
    int mask = ans | (1<<b);
    if ((mask & a[0][0]) != mask) {
      continue;
    }
    vector<vector<bool>> dp(n, vector<bool>(m));
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i][j]) {
          if (i+1 < n && (mask & a[i+1][j]) == mask) {
            dp[i+1][j] = true;
          }
          if (j+1 < m && (mask & a[i][j+1]) == mask) {
            dp[i][j+1] = true;
          }
        }
      }
    }
    if (dp[n-1][m-1]) {
      ans |= (1<<b);
    }
  }
  return ans;
}

void test() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  cout << incorrect_dp(a) << endl;
  cout << correct(a) << endl;
}

void solve() {
  // test();
  int k = 0;
  cin >> k;
  int n = 3, m = 3;
  int bits = 18;
  int mask = (1<<bits) - 1;
  vector<vector<int>> ans(n, vector<int>(m));
  ans[n-1][m-2] = ans[n-1][m-3] = mask;
  ans[1][0] = (1<<(bits-1));
  ans[0][0] = mask;
  ans[2][2] = mask >> 1;
  ans[1][2] = (mask >> 1) - k;
  ans[0][2] = (mask >> 1) - k;
  ans[0][1] = mask;
  ans[1][1] = mask >> 1;

  // cout << incorrect_dp(ans) << endl;
  // cout << correct(ans) << endl;

  cout << n << " " << m << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
