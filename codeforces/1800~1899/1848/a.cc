#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  int x0 = 0, y0 = 0;
  cin >> x0 >> y0;

  bool ans = true;
  for (int i = 0; i < k; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    int dist = abs(x-x0) + abs(y-y0);
    if (dist % 2 == 0) {
      ans = false;
    }
  }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
