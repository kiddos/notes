#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n = 0;
  cin >> n;

  ll ans = 0;
  while (n > 0) {
    ans += n;
    n /= 2;
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
