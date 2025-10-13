#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int size = n * n;
  if (size - k == 1) {
    cout << "NO" << endl;
    return;
  }
  vector<string> ans(n, string(n, ' '));
  int escape = k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (escape > 0) {
        escape--;
        ans[i][j] = 'L';
      } else {
        if (i == n-1) {
          if (j == n-1) {
            ans[i][j] = 'L';
          } else {
            ans[i][j] = 'R';
          }
        } else {
          ans[i][j] = 'D';
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
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
