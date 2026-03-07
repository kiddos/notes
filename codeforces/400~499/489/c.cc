#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int m = 0, s = 0;
  cin >> m >> s;
  if (m == 1) {
    if (s >= 0 && s <= 9) {
      cout << s << " " << s << endl;
    } else {
      cout << "-1 -1" << endl;
    }
    return;
  }

  int low = 1;
  int high = 9 * m;
  if (s < low || s > high) {
    cout << "-1 -1" << endl;
    return;
  }
  string min_val(m, '0');
  string max_val(m, '0');
  for (int i = 0, x = s; i < m && x > 0; ++i) {
    int take = min(x, 9);
    max_val[i] += take;
    x -= take;
  }
  min_val[0] = '1';
  for (int i = m-1, x = s-1; i >= 0 && x > 0; --i) {
    int take = min(x, 9);
    min_val[i] += take;
    x -= take;
  }
  cout << min_val << " " << max_val << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
