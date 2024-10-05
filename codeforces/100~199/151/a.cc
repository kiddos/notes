#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, l = 0, c = 0, d = 0, p = 0, nl = 0, np = 0;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  int total_lime_slice = c * d;
  int total_drink_liter = l * k;
  int toast_require_lime = n;
  int toast_require_drink = n * nl;
  int toast_require_salt = n * np;
  int ans = min({
    total_drink_liter / toast_require_drink,
    total_lime_slice / toast_require_lime,
    p / toast_require_salt,
  });
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
