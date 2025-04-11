#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;
  int y = x;
  for (int b = 31; b >= 0; --b) {
    if ((y & (1<<b))) {
      y ^= (1<<b);
      for (int b2 = b-1; b2 >= 0; --b2) {
        if (!(y& (1<<b2))) {
          y ^= (1<<b2);
          break;
        }
      }
      break;
    }
  }

  int z = x ^ y;
  vector<int> sides = {x, y, z};
  sort(sides.begin(), sides.end());
  if (sides[0] + sides[1] > sides[2]) {
    cout << y << endl;
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
