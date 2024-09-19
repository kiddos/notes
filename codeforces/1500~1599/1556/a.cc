#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int c = 0, d = 0;
  cin >> c >> d;
  if (c == 0 && d == 0) {
    cout << "0" << endl;
  } else if (c == d) {
    cout << "1" << endl;
  } else if (abs(c - d) % 2 == 1) {
    cout << "-1" << endl;
  } else {
    cout << "2" << endl;
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
