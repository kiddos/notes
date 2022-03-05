#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll n, ll s) {
  ll n2 = n*n;
  return s / n2;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t--) {
    ll n = 0, s = 0;
    cin >> n >> s;
    int ans = solve(n, s);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
