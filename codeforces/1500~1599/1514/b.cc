#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  constexpr int MOD = 1000000007;
  i64 ans = 1;
  for (int b = k-1; b >= 0; --b) {
    ans *= n;
    ans %= MOD;
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
