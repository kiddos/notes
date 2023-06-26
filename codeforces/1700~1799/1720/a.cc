#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;

  ll g = gcd(a, b);
  a /= g;
  b /= g;

  g = gcd(c, d);
  c /= g;
  d /= g;

  if (a == c && b == d) {
    cout << "0" << endl;
  } else if (a == 0 || b == 0) {
    cout << "1" << endl;
  } else {
    // f1 * x = f2
    // x = f2 / f1
    ll p = c * b;
    ll q = d * a;
    g = gcd(p, q);
    p /= g;
    q /= g;

    if (q == 1 || p == 1) {
      cout << "1" << endl;
    } else {
      cout << "2" << endl;
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
