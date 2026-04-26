#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  int x = 0;
  for (int bit = 0; bit < 32; ++bit) {
    if ((a & (1<<bit)) && (b & (1<<bit))) {
      x |= (1<<bit);
    }
  }
  int ans = (a ^ x) + (b ^ x);
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
