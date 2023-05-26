#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      cout << "1" << endl;
    } else if (i == 1) {
      cout << "1 1" << endl;
    } else {
      cout << "1 ";
      for (int j = 0; j < i-1; ++j) cout << "0 ";
      cout << "1" << endl;
    }
  }
}

//     1
//    1 1
//   1 0 1
//  1 0 0 1
// 1 0 0 0 1

//     1
//    2 2
//   3 3 3
//  4 4 4 4
// 5 5 5 5 5

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
