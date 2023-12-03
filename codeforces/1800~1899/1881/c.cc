#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> matrix(n);
  for (int i = 0; i < n; ++i) cin >> matrix[i];

  constexpr int INF = 1e9;
  int ans = 0;
  for (int i = 0; i < n/2; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      string s;
      s.push_back(matrix[i][j]);
      s.push_back(matrix[j][n-1-i]);
      s.push_back(matrix[n-1-i][n-1-j]);
      s.push_back(matrix[n-1-j][i]);
      int min_diff = INF;
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        int diff = 0;
        for (char c : s) {
          if (ch >= c) {
            diff += ch - c;
          } else {
            diff = INF;
          }
        }
        min_diff = min(min_diff, diff);
      }
      ans += min_diff;
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
