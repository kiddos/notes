#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int solve(int n, int m) {
  int ans = 0;
  while (n > 1) {
    n = (n+1) / 2;
    ans++;
  }
  while (m > 1) {
    m = (m+1) / 2;
    ans++;
  }
  return ans;
}

void solve() {
  int n = 0, m = 0, a = 0, b = 0;
  cin >> n >> m >> a >> b;

  int n2 = min(a, n - a + 1);
  int m2 = min(b, m - b + 1);
  int ans = min(solve(n2, m), solve(n, m2)) + 1;
  cout << ans << endl;
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
