#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0, x = 0;
  cin >> n >> k >> x;

  i64 min_val = (1 + k) * k / 2;
  i64 max_val = (n + n - k + 1) * k / 2;
  if (x >= min_val && x <= max_val) {
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
