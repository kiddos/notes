#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, n = 0, m = 0;
  cin >> x >> n >> m;
  for (int i = 0; i < n && x > 20; ++i) {
    x = (x / 2) + 10;
  }
  for (int i = 0; i < m && x > 0; ++i) {
    x -= 10;
  }

  if (x > 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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
