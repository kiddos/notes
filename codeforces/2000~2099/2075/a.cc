#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;

  i64 ans = 0;
  if (n % 2 == 1) {
    if (k % 2 == 1) {
      n -= k;
      ans++;
      k--;
    }
    i64 div = (n + k - 1) / k;
    ans += div;
  } else {
    if (k % 2 == 1) {
      k--;
    }
    i64 div = (n + k - 1) / k;
    ans += div;
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
