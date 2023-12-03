#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];
  int k = 0;
  cin >> k;
  for (int i = n-2; i >= 0; --i) {
    c[i] = min(c[i], c[i+1]);
  }
  
  vector<int> a(n);
  a[0] = k / c[0];
  int x = k - k / c[0] * c[0];
  for (int i = 1; i < n; ++i) {
    if (c[i] == c[i-1]) {
      a[i] = a[i-1];
    } else {
      int require = c[i] - c[i-1];
      a[i] = min(a[i-1], x / require);
      x = max(0, x - require * a[i]);
    }
  }

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
