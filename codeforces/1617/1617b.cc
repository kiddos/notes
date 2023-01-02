#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

array<ll, 3> solve(ll n) {
  ll b = 2;
  while (gcd(n - b - 1, b) > 1) {
    b++;
  }
  return {n-b-1, b, 1};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    ll n = 0;
    cin >> n;
    array<ll, 3> ans = solve(n);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
  cout << flush;
  return 0;
}
