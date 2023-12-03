#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  auto check = [&](int a, int b, int c) -> bool {
    return abs(b - c) % 2 == 0;
  };
  cout << check(a, b, c) << " "
    << check(b, a, c) << " "
    << check(c, a, b) << endl;
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
