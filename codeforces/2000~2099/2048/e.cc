#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  if (m >= n * 2) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  vector<int> colors;
  for (int i = 0; i < n; ++i) {
    colors.push_back(i+1);
    colors.push_back(i+1);
  }
  vector<vector<int>> ans(n*2, vector<int>(m));
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n * 2; ++i) {
      ans[i][j] = colors[(i-j+2*n) % (2*n)];
    }
  }
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout<< ans[i][j] << " ";
    }
    cout << endl;
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
