#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  int a = min(n, m);
  int b = max(n, m);
  if (a == 1) {
    if (b % 2 == 0) {
      cout << "Burenka" << endl;
    } else {
      cout << "Tonya" << endl;
    }
  } else {
    if (a % 2 == 0) {
      // tonya start with a = 0
      if (b % 2 == 0) {
        cout << "Tonya" << endl;
      } else {
        cout << "Burenka" << endl;
      }
    } else {
      // burenka start with a = 0
      if (b % 2 == 0) {
        cout << "Burenka" << endl;
      } else {
        cout << "Tonya" << endl;
      }
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
