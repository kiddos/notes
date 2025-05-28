#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, p = 0,q = 0;
  cin >> n >> m >> p >> q;
  if (n % p != 0) {
    cout << "YES" << endl;
  } else {
    int count = n / p;
    if (count * q == m) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
