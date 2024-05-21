#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  int screen_for_y = (y+1) / 2;
  int left = 5 * 3 * screen_for_y - 2 * 2 * y;
  if (x <= left) {
    cout << screen_for_y << endl;
  } else {
    x -= left;
    int screen_for_x = (x + 15-1) / 15;
    cout << screen_for_x + screen_for_y << endl;
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
