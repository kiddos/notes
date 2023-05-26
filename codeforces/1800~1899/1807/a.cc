#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  if (a + b == c) {
    cout << "+" << endl;
  } else {
    cout << "-" << endl;
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
