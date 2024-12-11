#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<vector<int>> p(256, vector<int>(256));

void prepare() {
  int k = 0;
  for (int i = 0; i < 256; i += 2) {
    for (int j = 0; j < 256; j += 2) {
      p[i][j] = k * 4;
      p[i][j+1] = k * 4 + 1;
      p[i+1][j] = k * 4 + 2;
      p[i+1][j+1] = k * 4 + 3;
      k++;
    }
  }
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  cout << n * m << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  prepare();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
