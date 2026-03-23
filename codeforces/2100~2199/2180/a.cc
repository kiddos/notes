#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, a = 0, b = 0;
  cin >> l >> a >> b;
  set<int> s = {a};
  while (true) {
    a = (a + b) % l;
    if (s.count(a)) {
      break;
    }
    s.insert(a);
  }
  int ans = *s.rbegin();
  cout << ans << endl;
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
