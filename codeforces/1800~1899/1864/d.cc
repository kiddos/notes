#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < n; ++j) {
      if (row[j] == '1') {
        matrix[i][j] = 1;
      }
    }
  }

  int ans = 0;
  vector<int> diag1(n*2+1);
  vector<int> diag2(n*2+1);
  for (int i = 0; i < n; ++i) {
    vector<int> next_diag1 = diag1;
    vector<int> next_diag2 = diag2;
    int p = 0;
    for (int j = -n; j < n; ++j) {
      int d1 = i+j;
      p += d1 >= 0 ? diag1[d1] : 0;
      int d2 = n-i-1+j;
      p += d2 >= 0 ? diag2[d2] : 0;

      // cout << p << " ";
      if (j >= 0) {
        int x = matrix[i][j] + p;
        if (x % 2 == 1) {
          // set diag
          next_diag1[i+j]++;
          next_diag2[n-i-1+j+1]--;
          ans++;
        }
      }
    }

    diag1 = move(next_diag1);
    diag2 = move(next_diag2);
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
