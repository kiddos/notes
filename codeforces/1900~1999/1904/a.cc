#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  i64 xk = 0, yk = 0;
  i64 xq = 0, yq = 0;
  cin >> a >> b >> xk >> yk >> xq >> yq;

  vector<vector<i64>> delta = {{a, b}, {a, -b}, {-a, b}, {-a, -b},
                               {b, a}, {b, -a}, {-b, a}, {-b, -a}};
  set<pair<i64, i64>> s;
  for (vector<i64> &d : delta) {
    i64 x = xq + d[0], y = yq + d[1];
    i64 dx = abs(x - xk), dy = abs(y - yk);
    if ((dx == a && dy == b) || (dx == b && dy == a)) {
      s.insert({x, y});
    }
  }

  cout << s.size() << endl;
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
