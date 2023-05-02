#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;
  ll x = d - b;
  ll y = a - c + d - b;
  if (a + x - y == c && b + x == d && x >= 0 && y >= 0) {
    cout << x + y << endl;
  } else {
    cout << "-1" << endl;
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
