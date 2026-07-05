#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  if (n == 1) {
    cout << "-1" << endl;
    return;
  } else if (n == 2) {
    int dx = abs(x[0] - x[1]);
    int dy = abs(y[0] - y[1]);
    if (dx != 0 && dy != 0) {
      int ans = dx * dy;
      cout << ans << endl;
    } else {
      cout << "-1" << endl;
    }
  } else {
    int dx = 0, dy =0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        dx = max(dx, abs(x[i] - x[j]));
        dy = max(dy, abs(y[i] - y[j]));
      }
    }
    int ans = dx * dy;
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
