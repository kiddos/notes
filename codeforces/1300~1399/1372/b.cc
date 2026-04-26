#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  for (int d = 2; d*d <= n; ++d) {
    if (n % d == 0) {
      int x = n / d;
      int y = n - x;
      cout << x << " " << y << endl;
      return;
    }
  }
  cout << "1 " << n-1 << endl;
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
