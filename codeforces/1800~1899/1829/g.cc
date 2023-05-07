#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAX_VAL = 1e6;
// constexpr int MAX_VAL = 15;

unordered_map<int, ll> results;

void precompute() {
  ll current = 1;
  ll level = 1;
  vector<vector<ll>> rows;
  while (current <= MAX_VAL) {
    vector<ll> row;
    for (int i = 0; i < level; ++i) {
      row.push_back(current);
      current++;
    }
    rows.push_back(row);
    level++;
  }

  int m = rows.size();
  vector<vector<ll>> dp = rows;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      dp[i][j] = dp[i][j] * dp[i][j];
    }
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      if (j < dp[i-1].size()) {
        dp[i][j] += dp[i-1][j];
      }
      if (j > 0) {
        dp[i][j] += dp[i-1][j-1];
      }
      if (i >= 2 && j > 0 && j-1 < dp[i-2].size()) {
        dp[i][j] -= dp[i-2][j-1];
      }
    }
  }

  // for (int i = 0; i < m; ++i) {
  //   for (int j = 0; j < dp[i].size(); ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      int val = rows[i][j];
      results[val] = dp[i][j];
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  cout << results[n] << endl;
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
