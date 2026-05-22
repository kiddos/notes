#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  i64 x = max(a, b), y = min(a, b);
  if (x % y != 0) {
    cout << "-1" << endl;
    return;
  }
  i64 div = x / y;
  if (bitset<64>(div).count() != 1) {
    cout << "-1" << endl;
    return;
  }
  int p = 0;
  while (div > 1) {
    div >>= 1;
    p++;
  }
  int ans = 0;
  while (p >= 3) {
    p -= 3;
    ans++;
  }
  if (p > 0) {
    p = 0;
    ans++;
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
