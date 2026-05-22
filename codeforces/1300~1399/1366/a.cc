#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  if (a > b * 2) {
    cout << b << endl;
  } else if (b > a * 2) {
    cout << a << endl;
  } else {
    i64 sum = a + b;
    cout << sum / 3 << endl;
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
