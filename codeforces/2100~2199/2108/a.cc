#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int max_diff = 0;
  for (int p = n, i = 1; p >= 1; --p, ++i) {
    max_diff += abs(i - p);
  }
  int ans = max_diff / 2 + 1;
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
