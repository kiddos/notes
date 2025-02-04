#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  if (l == 1 && r == 1) {
    cout << "1" << endl;
    return;
  }
  int ans = r - l;
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
