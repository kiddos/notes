#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  if (a == 1) {
    cout << b * b << endl;
  } else {
    i64 g = gcd(a, b);
    if (g == 1) {
      cout << a * b << endl;
    } else if (g == a) {
      cout << b * b / g << endl;
    } else {
      cout << a * b / g << endl;
    }
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
