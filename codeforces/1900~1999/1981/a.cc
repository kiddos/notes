#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  int score = 1;
  int ans = 0;
  for (i64 x = 2; x <= numeric_limits<int>::max(); x <<= 1, ++score) {
    if (x >= l && x <= r) {
      ans = max(ans, score);
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
