#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<vector<int>> a(5, vector<int>(5));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (a[i][j] == 1) {
        ans = abs(i - 2) + abs(j - 2);
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
