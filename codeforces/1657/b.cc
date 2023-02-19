#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll n, ll B, ll x, ll y) {
  ll ans = 0;
  ll a = 0;
  for (int i = 0; i < n; ++i) {
    if (a + x <= B) a += x;
    else a -= y;
    ans += a;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    ll n = 0, B = 0, x = 0, y = 0;
    cin >> n >> B >> x >> y;
    ll ans = solve(n, B, x, y);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
