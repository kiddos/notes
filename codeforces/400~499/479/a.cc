#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  int ans = max({
    (a + b) * c,
    a * (b + c),
    a * b * c,
    a + b * c,
    a * b + c,
    a + b + c,
  });
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
