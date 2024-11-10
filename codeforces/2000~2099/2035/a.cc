#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, r = 0, c = 0;
  cin >> n >> m >> r >> c;
  i64 shift = (n-r) * m;
  i64 move = (n-r) * (m-1) + m-c;
  i64 ans = shift + move;
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
