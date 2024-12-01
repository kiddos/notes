#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  for (i64 d = 2; d*d <= n; ++d) {
    if (n % d == 0) {
      i64 g = n / d;
      i64 f1 = 1, f2 = d - 1;
      i64 a = g * f1, b = g * f2;
      cout << a << " " << b << endl;
      return;
    }
  }

  cout << 1 << " " << n-1 << endl;
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
