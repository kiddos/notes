#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


// w*x + y*d = p
// x + y + z = n

void solve() {
  i64 n = 0, p = 0, d = 0, w = 0;
  cin >> n >> p >> w >> d;

  for (i64 y = 0; y < w; ++y) {
    i64 rest = p - y * d;
    // cout << "rest=" << rest << endl;
    if (rest < 0 || rest % w != 0) {
      continue;
    }
    i64 x = rest / w;
    i64 z = n - x - y;
    // cout << "z=" << z << endl;
    if (z >= 0) {
      cout << x << " " << y << " " << z << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
