#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  i64 min_sum = (2 * k - 1 + 1) * k / 2;
  if (min_sum > n) {
    cout << "NO" << endl;
    return;
  }
  i64 left = n - min_sum;
  if (left % 2 == 0) {
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
