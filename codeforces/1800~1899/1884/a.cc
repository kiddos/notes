#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool divisable(i64 x, int k) {
  int d = 0;
  while (x > 0) {
    d += x % 10;
    x /= 10;
  }
  return d % k == 0;
}

void solve() {
  i64 x = 0;
  int k = 0;
  cin >> x >> k;
  while (!divisable(x, k)) {
    x++;
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
