#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch = '0';
      cin >> ch;
      A[i][j] = ch-'0';
    }
  }

  int ones = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ones += A[i][j];
    }
  }

  auto max_zeros = [&](int r, int c) -> int {
    return max({
      !A[r-1][c-1] + !A[r-1][c] + !A[r][c-1],
      !A[r-1][c-1] + !A[r-1][c] + !A[r][c],
      !A[r-1][c-1] + !A[r][c-1] + !A[r][c],
      !A[r][c-1] + !A[r-1][c] + !A[r][c],
    });
  };

  int zeros = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      zeros = max(zeros, max_zeros(i, j));
    }
  }

  int ans = ones - max(2 - zeros, 0);
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
