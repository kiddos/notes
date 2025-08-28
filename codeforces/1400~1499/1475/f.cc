#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < n; ++j) {
      a[i][j] = row[j] - '0';
    }
  }
  string empty;
  getline(cin, empty);

  vector<vector<int>> b(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < n; ++j) {
      b[i][j] = row[j] - '0';
    }
  }
  vector<int> col(n);
  for (int j = 0; j < n; ++j) {
    if (a[0][j] != b[0][j]) {
      col[j] = 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    int x = (a[i][0]^col[0]) != b[i][0] ? 1 : 0;
    for (int j = 1; j < n; ++j) {
      if ((a[i][j] ^ col[j] ^ x) != b[i][j]) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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
