#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i <= 5; ++i) {
    for (int j = 0; j <= 5; ++j) {
      for (int k = 0; k <= 5; ++k) {
        if (i+j+k <= 5) {
          ans = max(ans, (i+a) * (j+b) * (k+c));
        }
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
