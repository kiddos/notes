#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
    sort(a[i].begin(), a[i].end());
  }
  vector<int> index(n);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&](int i1, int i2) {
    return a[i1][0] < a[i2][0];
  });
  for (int j = 0; j < m; ++j) {
    for (int i = 1; i < n; ++i) {
      if (a[index[i-1]][j] > a[index[i]][j]) {
        cout << "-1" << endl;
        return;
      }
    }
    if (j > 0) {
      if (a[index.back()][j-1] > a[index[0]][j]) {
        cout << "-1" << endl;
        return;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << index[i]+1 << " ";
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
