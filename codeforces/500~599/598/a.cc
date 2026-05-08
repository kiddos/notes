#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  i64 sum = (n + 1) * n / 2;
  i64 p = 1;
  while (p * 2 <= n) {
    p *= 2;
  }
  i64 geo = p * 2 - 1;
  i64 ans = sum - geo * 2;
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
