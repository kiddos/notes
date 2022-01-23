#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int INF = 1e6;
  int n = 5;
  vector<vector<int>> dp(n, vector<int>(n, INF));
  vector<vector<int>> next(n, vector<int>(n));
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      next[i][j] = j;
    }
  }
  dp[0][1] = dp[1][0] = 2;
  dp[0][4] = dp[4][0] = 8;
  dp[1][2] = dp[2][1] = 3;
  dp[1][4] = dp[4][1] = 2;
  dp[2][3] = dp[3][2] = 1;
  dp[3][4] = dp[4][3] = 1;

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][k] + dp[k][j] < dp[i][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }

  function<vector<int>(int,int)> shortest_path = [&](int start, int end) {
    vector<int> path;
    int node = start;
    while (node != end) {
      path.push_back(node);
      node = next[node][end];
    }
    path.push_back(end);
    return path;
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i != j) {
      auto path = shortest_path(i, j);
      cout << "shortest path from " << i << " to " << j << ": ";
      for (int node : path) {
        cout << node << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
