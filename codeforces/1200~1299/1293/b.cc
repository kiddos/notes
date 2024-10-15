#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1.0 / i;
  }
  cout << setprecision(12) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
