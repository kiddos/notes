#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  i64 ans = 0;
  for (int b = 1; b <= m; ++b) {
    i64 from = max(b-1, 1) * b;
    if (from > n) break;
    i64 b2 = b * b;
    i64 count = (n - from) / b2 + 1;
    // cout << "b=" << b <<  ", from=" << from << ", count=" << count << endl;
    ans += max(count, 0LL);
  }
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
