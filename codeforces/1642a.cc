#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int x0, int y0, int x1, int y1, int x2, int y2) {
  ll ans = 0;
  if (y0 == y1 && y0 != 0 && y2 < y0) ans += abs(x0 - x1);
  if (y0 == y2 && y0 != 0 && y1 < y0) ans += abs(x0 - x2);
  if (y1 == y2 && y1 != 0 && y0 < y1) ans += abs(x1 - x2);
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll x0 = 0, y0 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    ll ans = solve(x0, y0, x1, y1, x2, y2);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
