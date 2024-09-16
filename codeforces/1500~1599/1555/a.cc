#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  if (n <= 6) {
    cout << "15" << endl;
  } else if (n <= 8) {
    cout << "20" << endl;
  } else if (n <= 10) {
    cout << "25" << endl;
  } else {
    i64 ans = (n + n % 2) * 5 / 2;
    cout << ans << endl;
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
