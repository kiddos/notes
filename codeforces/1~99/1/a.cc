#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, a = 0;
  cin >> n >> m >> a;
  i64 x = (n + a - 1) / a;
  i64 y = (m + a - 1) / a;
  i64 ans = x * y;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
