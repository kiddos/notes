#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> val(3);
  for (int i = 0; i < 3; ++i) {
    cin >> val[i];
  }
  for (int a : val) {
    for (int b : val) {
      for (int c : val) {
        int x = max(a, b);
        int y = max(a, c);
        int z = max(b, c);
        if (x == val[0] && y == val[1] && z == val[2]) {
          cout << "YES" << endl;
          cout << a << " " << b << " " << c << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
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
