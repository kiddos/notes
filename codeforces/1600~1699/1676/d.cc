#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> board;
  for (int i = 0; i < n; ++i) {
    vector<int> row(m);
    for (int j = 0; j < m; ++j) {
      cin >> row[j];
    }
    board.push_back(row);
  }

  vector<int> diag1(n+m+1), diag2(n+m+1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      diag1[i+j] += board[i][j];
      diag2[i+(m-j-1)] += board[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int sum = diag1[i+j] + diag2[i+(m-j-1)] - board[i][j];
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
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
