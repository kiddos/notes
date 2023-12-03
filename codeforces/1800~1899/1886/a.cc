#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  // smallest is 1, 2, 4
  if (n < 7) {
    cout << "NO" << endl;
    return;
  }
  if (n % 3 == 0) {
    int x = 1;
    int y = 4;
    int z = n - 5;
    if (z == y || z == x) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
  } else if (n % 3 == 1) {
    int x = 1;
    int y = 2;
    int z = n - 3;
    if (z == y || z == x) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
  } else if (n % 3 == 2) {
    int x = 1;
    int y = 2;
    int z = n - 3;
    if (z == y || z == x) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
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
