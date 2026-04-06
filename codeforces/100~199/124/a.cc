#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, n = 0;
  cin >> n >> a >> b;
  int ans = min(n-a, b+1);
  ans = max(ans, 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
