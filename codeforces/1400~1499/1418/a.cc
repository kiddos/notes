#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 x = 0, y = 0, k = 0;
  cin >> x >> y >> k;

  i64 require_stick = y * k + k - 1;
  i64 gain = x-1;
  i64 trade = (require_stick + gain-1) / gain + k;
  cout << trade << endl;
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
