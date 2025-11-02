#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool inc(vector<int>& x) {
  int n = x.size();
  vector<vector<bool>> dp(n+1, vector<bool>(2));
  dp[0][0] = dp[0][1] = dp[1][1] = true;
  for (int i = 1; i < n; ++i) {
    if (x[i] - x[i-1] == 1 || x[i] - x[i-1] == 2 || x[i] - x[i-1] == 3) {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
    } else if (i >= 2 && (x[i] - x[i-2] == 1 || x[i] - x[i-2] == 2 || x[i] - x[i-2] == 3)) {
      dp[i][1] = dp[i-2][0];
    }
  }
  return dp[n-1][0] || dp[n-1][1] || (n >= 2 && dp[n-2][0]);
}

bool dec(vector<int>& x) {
  int n = x.size();
  vector<vector<bool>> dp(n, vector<bool>(2));
  dp[0][0] = dp[0][1] = dp[1][1] = true;
  for (int i = 1; i < n; ++i) {
    if (x[i-1] - x[i] == 1 || x[i-1] - x[i] == 2 || x[i-1] - x[i] == 3) {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
    } else if (i >= 2 && (x[i-2] - x[i] == 1 || x[i-2] - x[i] == 2 || x[i-2] - x[i] == 3)) {
      dp[i][1] = dp[i-2][0];
    }
  }
  return dp[n-1][0] || dp[n-1][1] || (n >= 2 && dp[n-2][0]);
}

bool safe(vector<int>& report) {
  if (inc(report) || dec(report)) {
    return true;
  }
  return false;
}

void solve() {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    stringstream ss;
    ss << line;
    int x = 0;
    vector<int> report;
    while (ss >> x) {
      report.push_back(x);
    }
    if (safe(report)) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
