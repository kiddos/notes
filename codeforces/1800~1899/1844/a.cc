#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  if (min(a, b) > 1) {
    cout << "1" << endl;
  } else {
    if (max(a, b) == 2) {
      cout << "3" << endl;
    } else {
      cout << "2" << endl;
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
