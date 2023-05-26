#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll a = 0, b = 0;
  cin >> a >> b;
  ll g = gcd(a, b);
  if (g == 1) {
    cout << "1" << endl;
    cout << a << " " << b << endl;
  } else {
    cout << "2" << endl;
    cout << (a-1) << " " << 1 << endl;
    cout << a << " " << b << endl;
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
