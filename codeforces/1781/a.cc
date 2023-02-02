#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int w = 0, d = 0, h = 0;
    cin >> w >> d >> h;
    int a = 0, b = 0, f = 0, g = 0;
    cin >> a >> b >> f >> g;

    int ans = min({
      abs(g-b) + 2*w - a - f + h,
      abs(g-b) + a + f + h,
      abs(a-f) + 2*d - b - g + h,
      abs(a-f) + b + g + h,
    });
    cout << ans << endl;
  }
  return 0;
}
