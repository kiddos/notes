#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> M(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> M[i][j];
  }

  vector<int> a = M[0];
  for (int i = 0; i < n-1; ++i) {
    a[i] = M[i][i+1];
    for (int j = i+1; j < n; ++j) {
      a[i] &= M[i][j];
    }
  }

  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      a[j] &= M[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (M[i][j] != (a[i] | a[j])) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
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
