#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;

  int noway = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == c[i] || b[i] == c[i]) {
      noway++;
    }
  }
  if (noway == n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
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
