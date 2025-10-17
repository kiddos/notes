#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 k = 0, x = 0;
  cin >> k >> x;
  for (int i = 0; i < k; ++i) {
    x *= 2;
  }
  cout << x << endl;
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
