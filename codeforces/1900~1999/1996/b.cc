#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  vector<string> ans;
  for (int i = 0; i < n; i += k) {
    string row;
    for (int j = 0; j < n; j += k) {
      row.push_back(grid[i][j]);
    }
    ans.push_back(row);
  }
  
  for (string& a : ans) {
    cout << a << endl;
  }
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
