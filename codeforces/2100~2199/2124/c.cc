#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> a = b;
  i64 x = 1;
  for (int i = n-2; i >= 0; --i) {
    int g = gcd(a[i], a[i+1]);
    i64 p = a[i] / g;
    i64 missing = p / gcd(p, x);
    x *= missing;
    a[i] = g;
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  cout << x << endl;
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
