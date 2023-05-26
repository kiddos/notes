#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n+1);

  b[0] = a[0];
  b.back() = a.back();
  for (int i = 1; i < n; ++i) {
    int g = gcd(a[i], a[i-1]);
    b[i] = a[i] * a[i-1] / g;
  }
  // for (int i = 0; i <= n; ++i) {
  //   cout << b[i] << " ";
  // }
  // cout << endl;

  for (int i = 1; i <= n; ++i) {
    if (gcd(b[i], b[i-1]) != a[i-1]) {
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
