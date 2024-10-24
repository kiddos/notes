#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  int ans = 0;
  for (int a = 0; a <= n && a * 2 <= m; ++a) {
    int b = min(m - a * 2, (n-a) / 2);
    int total = a + b;
    ans = max(ans, total);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
