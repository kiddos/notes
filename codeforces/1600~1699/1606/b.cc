#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  i64 copyed = 1;
  i64 ans = 0;
  n--;
  while (n > 0) {
    n -= copyed;
    copyed *= 2;
    ans += 1;
    if (copyed > k) break;
  }
  if (n > 0) {
    ans += (n + k - 1) / k;
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
