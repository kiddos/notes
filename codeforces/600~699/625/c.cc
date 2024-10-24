#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  k--;

  vector<vector<int>> a(n, vector<int>(n));
  int x = 1;
  for (int j = 0; j < k; ++j) {
    for (int i = 0; i < n; ++i) {
      a[i][j] = x++;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = k; j < n; ++j) {
      a[i][j] = x++;
    }
  }

  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i][k];
  }
  cout << sum << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
