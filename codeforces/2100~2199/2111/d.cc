#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  vector<vector<int>> ans(n, vector<int>(6));
  for (int j = 0; j < 6; ++j) {
    int half = (n+1) / 2;
    if (j % 2 == 0) {
      for (int i = 0; i < half; ++i) {
        ans[i][j] = a[i];
      }
      for (int i = n-1, k = m-1; i >= half; --i, --k) {
        ans[i][j] = a[k];
      }
    } else {
      for (int i = 0, k = m-1; i < half; ++i, --k) {
        ans[i][j] = a[k];
      }
      for (int i = n-1, k = 0; i >= half; --i, ++k) {
        ans[i][j] = a[k];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      cout << ans[i][j] << " ";
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
