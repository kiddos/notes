#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  if (k == 1) {
    cout << "1" << endl;
  } else if (k == 2) {
    if (n >= m) {
      cout << m << endl;
    } else {
      i64 ans = n - 1 + m / n;
      cout << ans << endl;
    }
  } else if (k == 3) {
    if (n >= m) {
      cout << "0" << endl;
    } else {
      // cout << "tmp=" << n - 1 + m / n << endl;
      i64 ans = max(m - (n - 1 + m / n), 0LL);
      cout << ans << endl;
    }
  } else {
    cout << "0" << endl;
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
