#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;
    bool beau = false;
    for (int i = 0; i < 4; ++i) {
      if (a < b && c < d && a < c && b < d) {
        beau = true;
        break;
      }
      int a2 = c, b2 = a, c2 = d, d2 = b;
      a = a2;
      b = b2;
      c = c2;
      d = d2;
    }
    if (beau) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
