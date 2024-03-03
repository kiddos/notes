#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<vector<int>> prefix(n, vector<int>(k+1));
  for (int i = 0; i < n; ++i) {
    int c = s[i] - '0';
    for (int j = k; j >= 0; --j) {
      if (c == 0) {
        prefix[i][j] = (i > 0 ? prefix[i-1][j] : 0) + 1;
      } else {
        if (j > 0) {
          prefix[i][j] = (i > 0 ? prefix[i-1][j-1] : 0) + 1;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      int& x = prefix[i][j];
      if (i > 0) x = max(x, prefix[i-1][j]);
      if (j > 0) x = max(x, prefix[i][j-1]);
    }
  }

  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j <= k; ++j) {
      //cout << prefix[i][j] << " ";
    //}
    //cout << endl;
  //}

  vector<vector<int>> suffix(n, vector<int>(k+1));
  for (int i = n-1; i >= 0; --i) {
    int c = s[i] - '0';
    for (int j = 0; j <= k; ++j) {
      if (c == 0) {
        suffix[i][j] = (i+1 < n ? suffix[i+1][j] : 0) + 1;
      } else {
        if (j > 0) {
          suffix[i][j] = (i+1 < n ? suffix[i+1][j-1] : 0) + 1;
        }
      }
    }
  }

  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j <= k; ++j) {
      int& x = suffix[i][j];
      if (i+1 < n) x = max(x, suffix[i+1][j]);
      if (j > 0) x = max(x, suffix[i][j-1]);
    }
  }

  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j <= k; ++j) {
      //cout << suffix[i][j] << " ";
    //}
    //cout << endl;
  //}

  vector<int> dp(n+1, -1);
  dp[prefix[n-1][k]] = max(dp[prefix[n-1][k]], prefix[n-1][k]);
  for (int l = 0; l < n; ++l) {
    int require = 0;
    for (int r = l; r < n; ++r) {
      require += s[r] == '0';
      if (require > k) {
        break;
      }

      int zero = max(l > 0 ? prefix[l-1][k-require] : 0,
                     r+1 < n ? suffix[r+1][k-require] : 0);
      int ones = r-l + 1;
      int total = zero + ones;
      dp[total] = max(dp[total], zero);
    }
  }

  //for (int i = 0; i <= n; ++i) {
    //cout << dp[i] << " ";
  //}
  //cout << endl;

  for (int a = 1; a <= n; ++a) {
    int ans = 0;
    for (int len = 0; len <= n; ++len) {
      if (dp[len] >= 0) {
        int l0 = dp[len];
        int l1 = len - l0;
        ans = max(ans, l0 * a + l1);
      }
    }
    cout << ans << " ";
  }
  cout << endl;
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
