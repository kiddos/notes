#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll solve(vector<ll>& a) {
  int n = a.size();
  ll gcd0 = a[0], gcd1 = a[1];
  for (int i = 2; i < n; i += 2) {
    gcd0 = gcd(gcd0, a[i]);
    if (i+1 < n) gcd1 = gcd(gcd1, a[i+1]);
  }
  for (int i = 0; i < n; i += 2) {
    if (gcd0 != 0 && i +1 < n && a[i+1] % gcd0 == 0) {
      gcd0 = 0;
    }
    if (gcd1 != 0 && a[i] % gcd1 == 0) {
      gcd1 = 0;
    }
  }
  return max(gcd1, gcd0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = solve(a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
