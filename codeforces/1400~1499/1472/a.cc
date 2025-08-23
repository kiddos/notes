#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 w = 0, h = 0, n = 0;
  cin >> w >> h >> n;

  auto cut = [&](i64 x) -> i64 {
    i64 part = 1;
    while (x % 2 == 0) {
      part *= 2;
      x /= 2;
    }
    return part;
  };

  i64 w_parts = cut(w);
  i64 h_parts = cut(h);
  i64 total = w_parts * h_parts;
  if (total >= n) {
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
