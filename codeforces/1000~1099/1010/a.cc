#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// (m + f) / b[i] = f
// m + f = b[i] * f
// f = m / (b[i] - 1)

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] == 1 || b[i] == 1) {
      cout << "-1" << endl;
      return;
    }
  }

  double mass = m;
  mass += mass / (b[0] - 1);
  for (int i = n-1; i >= 0; --i) {
    double fuel = mass / (a[i] - 1);
    mass += fuel;
    if (i != 0) {
      fuel = mass / (b[i] - 1);
      mass += fuel;
    }
  }
  double ans = mass - m;
  cout << fixed << setprecision(10) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
