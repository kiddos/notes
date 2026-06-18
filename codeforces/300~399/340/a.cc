#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0, a = 0, b = 0;
  cin >> x >> y >> a >> b;
  int g = gcd(x, y);
  int l = x * y / g;
  int ans = b / l - (a-1) / l;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
