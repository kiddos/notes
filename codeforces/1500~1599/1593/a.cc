#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  auto answer = [&](i64 a, i64 b, i64 c) -> i64 {
    return max(max(b, c) + 1 - a, 0LL);
  };

  cout << answer(a, b, c) << " "
    << answer(b, a, c) << " "
    << answer(c, a, b) << endl;
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
