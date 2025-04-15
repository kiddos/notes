#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, l = 0, r = 0;
  cin >> n >> m >> l >> r;

  int right = min(r, m);
  m -= right;
  int left = min(-l, m);
  cout << -left << " " << right << endl;
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
