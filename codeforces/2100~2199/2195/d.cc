#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }

  vector<int> a(n);
  for (int i = 1; i+1 < n; ++i) {
    a[i] = (f[(i-1+n)%n] + f[(i+1)%n]) - 2 * f[i];
    a[i] /= 2;
  }
  i64 sum = (f[0] + f[n-1]) / (n-1);
  a[0] = (f[1] + f[n-1] - sum * (n-2)) / 2;
  a[n-1] = (f[0] + f[n-2] - sum * (n-2)) / 2;
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
