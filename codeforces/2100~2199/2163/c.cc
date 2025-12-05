#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> max_vals = a;
  vector<vector<int>> min_vals = a;
  for (int j = 1; j < n; ++j) {
    max_vals[0][j] = max(max_vals[0][j], max_vals[0][j-1]);
    min_vals[0][j] = min(min_vals[0][j], min_vals[0][j-1]);
  }
  for (int j = n-2; j >= 0; --j) {
    max_vals[1][j] = max(max_vals[1][j], max_vals[1][j+1]);
    min_vals[1][j] = min(min_vals[1][j], min_vals[1][j+1]);
  }
  i64 left = 0, right = 0;
  i64 ans = 0;
  //   (a + a1) x (b + b1)
  // = a * b + a * b1 + a1 * b + a1 * b1
  for (int j = 0; j < n; ++j) {
    int max_val = max(max_vals[0][j], max_vals[1][j]);
    int min_val = min(min_vals[0][j], min_vals[1][j]);
    i64 l = min_val - 1 + 1;
    i64 r = 2 * n - max_val + 1;
    if (l > left && r > right) {
      i64 l1 = l - left;
      i64 r1 = r - right;
      ans += l1 * right;
      ans += r1 * left;
      ans += l1 * r1;
      left = l;
      right = r;
    } else if (l > left) {
      ans += (l - left) * r;
      left = l;
    } else if (r > right) {
      ans += (r - right) * l;
      right = r;
    }
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
