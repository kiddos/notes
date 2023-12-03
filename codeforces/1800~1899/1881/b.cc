#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  i64 len = gcd(gcd(a, b), c);
  i64 op = a / len - 1 + b / len - 1 + c / len - 1;
  if (op <= 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
