#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  int g = gcd(a, b);
  int a0 = a / g;
  int b0 = b / g;
  if (a0 > 1 && b0 > 1) {
    cout << "2" << endl;
  } else if (a0 > 1 || b0 > 1) {
    cout << "1" << endl;
  } else {
    cout << "0" << endl;
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
