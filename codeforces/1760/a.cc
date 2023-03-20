#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    int max_val = max({a, b, c});
    int min_val = min({a, b, c});
    if (a != max_val && a != min_val) cout << a << endl;
    else if (b != max_val && b != min_val) cout << b << endl;
    else if (c != max_val && c != min_val) cout << c << endl;
  }
  return 0;
}
