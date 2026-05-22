#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0, x = 0;
  cin >> k >> x;
  int ans = k * x + 1;
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
