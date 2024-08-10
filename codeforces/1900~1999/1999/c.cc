#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, s = 0, m = 0;
  cin >> n >> s >> m;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  if (l[0] >= s) {
    cout << "YES" << endl;
    return;
  }
  for (int i = 1; i < n; ++i) {
    int time = l[i] - r[i-1];
    if (time >= s) {
      cout << "YES" << endl;
      return;
    }
  }
  if (m - r.back() >= s) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
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
