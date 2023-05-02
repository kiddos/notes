#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  if (n < 9) {
    cout << "0" << endl;
  } else {
    n -= 3;
    int a = 1;
    int b = n / 3;
    int c = n - b - a;
    cout << min(abs(b-a), abs(c-a)) << endl;
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
