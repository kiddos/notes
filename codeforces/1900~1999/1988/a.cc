#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  if (n == 1) {
    cout << "0" << endl;
    return;
  }

  if (n <= k) {
    cout << "1" << endl;
    return;
  }

  int ans = 0;
  while (n > 1) {
    n -= (k-1);
    ans++;
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
