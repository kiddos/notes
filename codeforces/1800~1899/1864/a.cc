#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0, n = 0;
  cin >> x >> y >> n;
  vector<int> a(n);
  a[n-1] = y;
  for (int i = n-2, d = 1; i >= 0; --i, d++) {
    a[i] = a[i+1] - d;
    if (a[i] < x) {
      cout << "-1" << endl;
      return;
    }
  }
  a[0] = x;

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
