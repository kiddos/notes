#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  a = abs(a);
  b = abs(b);
  int diag = min(a, b);
  int rest = max(a - diag, b - diag);
  int ans = diag * 2;
  if (rest) {
    ans += (rest + rest - 1);
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
