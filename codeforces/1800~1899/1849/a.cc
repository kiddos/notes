#include <bits/stdc++.h>

using namespace std;

void solve() {
  int b = 0, c = 0, h = 0;
  cin >> b >> c >> h;

  int pair = min(b-1, c + h);
  int layer = 1 + pair * 2;
  cout << layer << endl;
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
