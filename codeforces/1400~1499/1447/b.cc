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
  }

  vector<i64> abs_vals;
  int negs = 0, zeros = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      abs_vals.push_back(abs(a[i][j]));
      if (a[i][j] < 0) {
        negs++;
      }
      if (a[i][j] == 0) {
        zeros++;
      }
    }
  }
  int min_val = *min_element(abs_vals.begin(), abs_vals.end());
  int sum = accumulate(abs_vals.begin(), abs_vals.end(), 0);
  int ans = sum;
  if (negs % 2 == 1 && zeros == 0) {
    ans = sum - min_val * 2;
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
