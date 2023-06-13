#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  int first = abs(a-1);
  int second = abs(b - c) + abs(c - 1);
  if (first < second) {
    cout << "1" << endl;
  } else if (second < first) {
    cout << "2" << endl;
  } else {
    cout << "3" << endl;
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
