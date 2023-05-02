#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll a, ll b, ll n, ll m) {
  if (n >= m+1) {
    ll a_amount = n / (m+1);
    ll left = n - a_amount * (m+1);
    ll ans = min({a_amount * m * a + left * a, a_amount * m * a + left * b, n * b});
    cout << ans << endl;
  } else {
    ll ans = min(n * a, n * b);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int a = 0, b = 0, n = 0, m = 0;
    cin >> a >> b >> n >> m;

    solve(a, b, n, m);
  }
  return 0;
}
