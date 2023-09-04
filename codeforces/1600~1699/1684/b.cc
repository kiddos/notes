#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  i64 z = c;
  i64 y = b + z * 2;
  i64 x = a + y * 2;
  cout << x << " " << y << " " << z << endl;
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
