#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n = 0, k = 0, g = 0;

  cin >> n >> k >> g;
  ll g2 = max((g+1) / 2 - 1, 0LL);

  ll total = k * g;
  ll save = min((n-1) * g2, total);
  ll last_x = total - save;
  ll r = last_x % g;
  if (r >= (g+1) / 2) {
    save -= (g-r);
  } else {
    save += r;
  }

  cout << save << endl;
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
