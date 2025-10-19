#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  i64 ans = -1;

  i64 a2 = a * b;
  i64 b2 = 1;
  if ((a2 + b2) % 2 == 0) {
    ans = max(ans, a2 + b2);
  }

  if (b % 2 == 0) {
    i64 b3 = 2;
    i64 a3 = a * (b / 2);
    if ((a3 + b3) % 2 == 0) {
      ans = max(ans, a3 + b3);
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
