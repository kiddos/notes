#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, m = 0;
  cin >> n >> x >> m;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }
  pair<int,int> current = {x, x};
  for (int i = 0; i < m; ++i) {
    if (max(current.first, l[i]) <= min(current.second, r[i])) {
      current.first = min(current.first, l[i]);
      current.second = max(current.second, r[i]);
    }
  }

  int ans = current.second - current.first + 1;
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
