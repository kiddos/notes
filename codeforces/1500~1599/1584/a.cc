#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 u = 0, v = 0;
  cin >> u >> v;
  i64 x = -u * u, y = v * v;
  cout << x << " " << y << endl;
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
