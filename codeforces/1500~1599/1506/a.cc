#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, x = 0;
  cin >> n >> m >> x;
  x--;
  i64 c = x / n;
  i64 r = x % n;
  i64 y = r * m + c + 1;
  cout << y << endl;
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
