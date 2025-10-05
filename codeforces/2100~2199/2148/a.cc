#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, n = 0;
  cin >> x >> n;
  if (n % 2 == 0) {
    cout << "0" << endl;
  } else {
    cout << x << endl;
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
