#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, x = 0, p = 0;
  cin >> n >> x >> p;

  for (ll y = 1; y <= min(2*n, p); ++y) {
    ll sum = x + (y + 1) * y / 2;
    // if (sum > min(2 * n, p)) break;
    if (sum % n == 0) {
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
