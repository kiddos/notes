#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, l = 0;
  cin >> a >> b >> l;

  i64 c = 1;
  set<int> possible;
  for (int x = 0; c <= l; c *= a, ++x) {
    i64 d = 1;
    for (int y = 0; c * d <= l; d *= b, ++y) {
      if (l % (d * c) == 0) {
        possible.insert(l / (d * c));
      }
    }
  }
  cout << possible.size() << endl;
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
