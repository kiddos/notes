#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  if (x < y) {
    swap(x, y);
  }

  if (y != 0) {
    cout << "-1" << endl;
    return;
  }
  
  if (x == 0) {
    cout << "-1" << endl;
    return;
  }

  if ((n-1) % x != 0) {
    cout << "-1" << endl;
    return;
  }

  int p = 2;
  for (int i = 0; i < (n-1)/x; ++i) {
    for (int j = 0; j < x; ++j) cout << p << " ";
    p += x;
  }
  cout << endl;
}

// 2,1
// 2,3
// 4,2
// 4,5
// 6,4
// 6,7
// 8,9
// 8,10

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
