#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  int msb_a = 31 - __builtin_clz(a);
  int msb_b = 31 - __builtin_clz(b);
  if (msb_b > msb_a) {
    cout << "-1" << endl;
    return;
  }

  int ans1 = 0;
  for (int bit = 0; bit < 32; ++bit) {
    int mask = 1<<bit;
    if (!(a & mask) && (b & mask)) {
      ans1 |= mask;
    }
  }

  int ans2 = 0;
  for (int bit = 0; bit < 32; ++bit) {
    int mask = 1<<bit;
    if ((a & mask) && !(b & mask)) {
      ans2 |= mask;
    }
  }

  cout << "2" << endl;
  cout << ans1 << " " << ans2 << endl;
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
