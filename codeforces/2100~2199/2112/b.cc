#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i-1]) <= 1) {
      cout << "0" << endl;
      return;
    }
  }

  for (int i = 2; i < n; ++i) {
    int x = a[i-2], y = a[i-1], z = a[i];
    if ((y >= x && y >= z) || (y <= x && y <= z)) {
      cout << "1" << endl;
      return;
    }
  }
  cout << -1 << endl;
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
