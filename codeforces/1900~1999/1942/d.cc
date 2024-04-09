#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Cell {
  i64 total;
  int r, c;
};

struct CompareCell {
  bool operator()(const Cell& c1, const Cell& c2) {
    return c1.total < c2.total;
  }
};

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<vector<int>> a;
  a.push_back(vector<int>(n+1));
  for (int i = 1; i <= n; ++i) {
    vector<int> row(n+1);
    for (int j = i; j <= n; ++j) cin >> row[j];
    a.push_back(row);
  }

  vector<vector<i64>> dp(n+1);
  dp[0] = {0};
  for (int i = 1; i <= n; ++i) {
    priority_queue<Cell, vector<Cell>, CompareCell> pq;
    pq.push({dp[i-1][0], i-1, 0});

    for (int j = -1; j <= i-2; ++j) {
      i64 dp0 = j >= 0 ? dp[j][0] : 0;
      pq.push(Cell{dp0 + a[j+2][i], j, 0});
    }

    while (!pq.empty() && (int)dp[i].size() < k) {
      auto [dp0, r, c] = pq.top();
      pq.pop();
      dp[i].push_back(dp0);

      if (r < 0 || c+1 >= (int)dp[r].size()) {
        continue;
      }

      if (r == i-1) {
        pq.push(Cell{dp[i-1][c+1], i-1, c+1});
      } else {
        pq.push(Cell{dp[r][c+1] + a[r+2][i], r, c+1});
      }
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (i64 x : dp[i]) cout << x << " ";
  //   cout << endl;
  // }

  for (i64 x : dp[n]) {
    cout << x << " ";
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
