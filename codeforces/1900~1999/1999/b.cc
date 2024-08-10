#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a[2] = {0};
  int b[2] = {0};
  cin >> a[0] >> a[1] >> b[0] >> b[1];
  int ans = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      int win = 0;
      if (a[i] > b[j]) {
        win++;
      } else if (b[j] > a[i]) {
        win--;
      }
      if (a[1-i] > b[1-j]) {
        win++;
      } else if (b[1-j] > a[1-i]) {
        win--;
      }

      if (win >= 1) {
        ans++;
      }
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
