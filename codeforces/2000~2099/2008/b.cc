#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int r = sqrt(n);
  if (r * r != n) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < r; ++i) {
    string row = s.substr(i * r, r);
    if (i == 0 || i == r-1) {
      if (row != string(r, '1')) {
        cout << "NO" << endl;
        return;
      }
    } else {
      string expect = "1" + string(r-2, '0') + "1";
      if (row != expect) {
        cout << "NO" << endl;
        return;
      }
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
