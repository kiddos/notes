#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;
  constexpr int MAX_N = 10000;
  int ans = 0;
  for (int d = 1; d <= 9; ++d) {
    for (int val = d, digits = 1; val <= MAX_N; val = val * 10 + d, ++digits) {
      ans += digits;
      if (val == x) {
        cout << ans << endl;
        return;
      }
    }
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
