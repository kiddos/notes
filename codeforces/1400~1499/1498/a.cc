#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int digits(i64 x) {
  int d = 0;
  while (x > 0) {
    d += x % 10;
    x /= 10;
  }
  return d;
}

void solve() {
  i64 n = 0;
  cin >> n;
  while (true) {
    if (gcd(n, digits(n)) > 1) {
      break;
    }
    n++;
  }
  cout << n << endl;
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
