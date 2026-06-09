#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 t = 0;
  cin >> n >> t;
  double p = 1.000000011;
  double ans = n;
  while (t > 0) {
    if (t % 2 == 1) {
      ans *= p;
    }
    p = (p * p);
    t >>= 1;
  }
  cout << fixed << setprecision(9) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
