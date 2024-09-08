#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;

  int L = 0, R = 100000000;
  while (L <= R) {
    i64 mid = L + (R-L) / 2;
    i64 total_diff = (1 + mid) * mid / 2;
    if (l + total_diff <= r) {
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  cout << L << endl;
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
