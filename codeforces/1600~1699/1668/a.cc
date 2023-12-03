#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  if (min(n, m) == 1) {
    if (max(n, m) > 2) {
      cout << "-1" << endl;
    } else {
      cout << max(n, m) - 1 << endl;
    }
  } else {
    int left = m - 1;
    int down = n - 1;
    if (abs(left - down) > 1) {
      int extra = abs(left - down) - 1;
      // cout << "exta=" << extra << endl;
      int ans = left + down + (extra / 2 * 2) + (extra - extra / 2 * 2) * 2;
      cout << ans << endl;
    } else {
      cout << left + down << endl;
    }
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
