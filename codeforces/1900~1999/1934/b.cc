#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int ans = n;
  for (int a = 0; a < 3; ++a) { // 1
    for (int b = 0; b < 2; ++b) { // 3
      for (int c = 0; c < 5; ++c) { // 6
        for (int d = 0; d < 3; ++d) { // 10
          int sum = a + b * 3 + c * 6 + d * 10;
          int rest = n - sum;
          if (rest >= 0 && rest % 15 == 0) {
            ans = min(ans, a + b + c + d + rest / 15);
          }
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
