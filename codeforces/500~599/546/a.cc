#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 k = 0, n = 0, w = 0;
  cin >> k >> n >> w;
  i64 total = (1 + w) * w / 2 * k;
  i64 ans = max(total - n, 0LL);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
