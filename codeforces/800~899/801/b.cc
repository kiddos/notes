#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string x, y;
  cin >> x >> y;
  string z = y;
  int n = z.length();
  for (int i = 0; i < n; ++i) {
    if (min(x[i], z[i]) != y[i]) {
      cout << "-1" << endl;
      return;
    }
  }
  cout << z << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
