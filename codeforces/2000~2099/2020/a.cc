#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  i64 p = 1;
  while (k > 1 && p * k <= n) {
    p *= k;
  }
  int ans = 0;
  while (n > 0) {
    ans += n / p;
    n -= n / p * p;
    p /= k;
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
