#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  if ((n * a[1] - a[n]) % (n * n - 1) != 0) {
    cout << "NO" << endl;
    return;
  }

  int y = (n * a[1] - a[n]) / (n * n - 1);

  if ((a[n] - y) % n != 0) {
    cout << "NO" << endl;
    return;
  }

  int x = (a[n] - y) / n;

  if (x < 0 || y < 0) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (i * x + (n-i+1) * y != a[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
