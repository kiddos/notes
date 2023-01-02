#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    int l = 0, r = 0;
    cin >> l >> r;
    int b = max((r + 1) / 2, l);
    int a = min(b * 2 - 1, r);
    cout << a % b << endl;
  }

  return 0;
}
