#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;
  swap(a[0], b[0]);
  cout << a << " " << b << endl;
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
