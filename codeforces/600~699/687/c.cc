#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<vector<bool>> dp(k+1, vector<bool>(k+1));
  dp[0][0] = true;
  for (int i = 0; i < n; ++i) {
    vector<vector<bool>> dp2 = dp;
    for (int j = 0; j <= k; ++j) {
      for (int s = 0; s <= k; ++s) {
        if (dp[j][s]) {
          if (s+c[i] <= k) {
            dp2[j][s+c[i]] = true;
            dp2[c[i]][s+c[i]] = true;
            dp2[j+c[i]][s+c[i]] = true;
          }
        }
      }
    }
    dp = std::move(dp2);
  }

  vector<int> ans;
  for (int j = 0; j <= k; ++j) {
    if (dp[j][k]) {
      ans.push_back(j);
    }
  }
  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
