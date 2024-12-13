#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, a = 0, b = 0;
  cin >> n >> a >> b;

  if (a == 1) {
    if ((n - 1) % b == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    i64 x = 1;
    while (x <= n) {
      i64 diff = n - x;
      if (diff % b == 0) {
        cout << "YES" << endl;
        return;
      }
      x *= a;
    }
    cout << "NO" << endl;
  }
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
