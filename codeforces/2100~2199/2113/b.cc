#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool possible(int x1, int x2, int a) {
  if (x1 + a <= x2) {
    int diff = x2 - (x1 + a);
    if (diff % a == 0) {
      return true;
    }
  } else if (x2 + a <= x1) {
    int diff = x2 - (x1 + a);
    if (diff % a == 0) {
      return true;
    }
  }
  return false;
}

void solve() {
  int w = 0, h = 0, a = 0, b = 0;
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> w >> h >> a >> b;
  cin >> x1 >> y1 >> x2 >> y2;
  if (possible(x1, x2, a) || possible(y1, y2, b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
