#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll l, ll r, ll a) {
  ll ans = r / a + r % a;
  ll m = r / a * a - 1;
  if (m >= l) ans = max(ans, m / a + m % a);
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    ll l = 0, r = 0, a = 0;
    cin >> l >> r >> a;
    ll ans = solve(l, r, a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
