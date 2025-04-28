#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> miners, diamonds;
  for (int i = 0; i < 2 * n; ++i) {
    i64 x = 0, y = 0;
    cin >> x >> y;
    if (x == 0) {
      miners.push_back(abs(y));
    } else if (y == 0) {
      diamonds.push_back(abs(x));
    }
  }

  sort(miners.begin(), miners.end());
  sort(diamonds.begin(), diamonds.end());
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += sqrt(miners[i] * miners[i] + diamonds[i] * diamonds[i]);
  }
  cout << fixed << setprecision(12) << ans << endl;
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
