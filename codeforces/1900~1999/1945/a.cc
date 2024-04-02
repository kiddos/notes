#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  int left = b % 3;
  int require = left > 0 ? 3 - left : 0;
  if (c < require) {
    cout << "-1" << endl;
    return;
  }

  c -= require;
  b += require;
  i64 ans = a + b / 3 + (c + 2) / 3;
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
