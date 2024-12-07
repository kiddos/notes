#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  i64 diff = abs(a - b);
  if (diff == 0) {
    cout << "0 0" << endl;
    return;
  }

  i64 min_val = min(a, b);
  i64 bound1 = (min_val + diff-1) / diff * diff;
  i64 bound2 = min_val / diff * diff;
  i64 change = min(min_val - bound2, bound1 - min_val);
  cout << diff << " " << change << endl;
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
