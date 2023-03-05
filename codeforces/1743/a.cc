#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      cin >> a;
    }
    int m = 10 - n;
    int ans = (m-1) * m / 2 * 6;
    cout << ans << endl;
  }
  return 0;
}
