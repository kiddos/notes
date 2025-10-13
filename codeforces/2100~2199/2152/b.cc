#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, rk = 0, ck = 0, rd = 0, cd = 0;
  cin >> n >> rk >> ck >> rd >> cd;

  int ans = 0;
  if (rk < rd) {
    // try to move to 0-row
    ans = max(ans, rd);
  } else if (rk > rd) {
    // try to move to n+1 row
    ans = max(ans, n- rd);
  }

  if (ck < cd) {
    // try to move to 0-col
    ans = max(ans, cd);
  } else if (ck > cd) {
    // try to move to n+1 col
    ans = max(ans, abs(n - cd));
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
