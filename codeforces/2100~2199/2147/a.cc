#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  if (x < y) {
    cout << "2" << endl;
  } else {
    // x = a + b
    // a < y < b
    if (x >= y + 2 && y > 1) {
      cout << "3" << endl;
    } else {
      cout << "-1" << endl;
    }
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
