#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int ans = numeric_limits<int>::max();
  for (int d = 1; d*d <= n; ++d) {
    if (n % d == 0) {
      int w = n / d;
      int l = d;
      ans = min(ans, w * 2 + l * 2);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
