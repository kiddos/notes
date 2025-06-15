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

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if (n % 2 == 0) {
    int x1 = x[n/2-1], x2 = x[n/2];
    int y1 = y[n/2-1], y2 = y[n/2];
    i64 w = x2-x1+1;
    i64 h = y2-y1+1;
    i64 ans = w * h;
    cout << ans << endl;
  } else {
    cout << "1" << endl;
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
