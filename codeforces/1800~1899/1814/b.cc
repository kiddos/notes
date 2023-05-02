#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAX_LEG = 100000;

void solve() {
  ll a = 0, b = 0;
  cin >> a >> b;

  ll ans = a + b;
  for (int leg = 1; leg <= MAX_LEG; ++leg) {
    ll moves = (a + leg - 1) / leg + (b + leg - 1) / leg + (leg - 1);
    ans = min(ans, moves);
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
