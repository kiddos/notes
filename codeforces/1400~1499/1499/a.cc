#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k1 = 0, k2 = 0;
  cin >> n >> k1 >> k2;
  int w = 0, b = 0;
  cin >> w >> b;

  int both_white = min(k1, k2);
  int white = both_white + (k1-both_white) / 2 + (k2-both_white) / 2;
  int both_black = min(n-k1, n-k2);
  int black = both_black + (n-k1-both_black) / 2 + (n-k2-both_black) / 2;
  if (w <= white && b <= black) {
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
