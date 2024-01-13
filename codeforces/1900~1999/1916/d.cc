#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  int m = n / 2;
  for (int i = 0; i < m; ++i) {
    cout << "1" << string(i, '0') << "6" << string(i, '0') << "9" << string((m-i-1) * 2, '0') << endl;
    cout << "9" << string(i, '0') << "6" << string(i, '0') << "1" << string((m-i-1) * 2, '0') << endl;
  }
  cout << "196" << string((m-1) * 2, '0') << endl;
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
