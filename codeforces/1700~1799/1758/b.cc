#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  if (n % 2 == 1) {
    for (int i = 0; i < n; ++i) cout << "1 ";
    cout << endl;
  } else {
    cout << "1 3 ";
    for (int i = 2; i < n; ++i) {
      cout << "2 ";
    }
    cout << endl;
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
