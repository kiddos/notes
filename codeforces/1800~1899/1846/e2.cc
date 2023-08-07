#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll power_sum(ll k, ll p) {
  ll sum = 0;
  ll x = 1;
  for (int i = 0; i <= p; ++i) {
    sum += x;
    x *= k;
  }
  return sum;
}

void solve() {
  ll n = 0;
  cin >> n;
  for (int p = 2; p <= log(n) / log(2); ++p) {
    ll k = pow(n, 1.0 / p);
    if (power_sum(k, p) == n) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
