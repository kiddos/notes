#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  i64 total = accumulate(p.begin(), p.end(), 0LL);
  i64 ans = total;
  int m = 1<<n;
  for (int mask = 0; mask < m; ++mask) {
    i64 current = 0;
    for (int b = 0; b < n; ++b) {
      if (mask & (1<<b)) {
        current += p[b];
      }
    }
    i64 other = total - current;
    i64 diff = abs(current - other);
    ans = min(ans, diff);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
