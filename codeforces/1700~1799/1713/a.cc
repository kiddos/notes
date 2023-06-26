#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> X = {0}, Y = {0};
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    if (x == 0) {
      Y.push_back(y);
    } else if (y == 0) {
      X.push_back(x);
    }
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int ans = 0;
  ans += (X.back() - X[0]) * 2;
  ans += (Y.back() - Y[0]) * 2;
  cout << ans << endl;
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
