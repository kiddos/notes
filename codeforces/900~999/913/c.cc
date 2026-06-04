#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, L = 0;
  cin >> n >> L;
  vector<i64> c(32, numeric_limits<i64>::max());
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  for (int b = 1; b <= 31; ++b) {
    c[b] = min(c[b], c[b-1]*2);
  }
  for (int b = 30; b >= 0; --b) {
    c[b] = min(c[b], c[b+1]);
  }

  i64 ans = 0;
  for (int b = 0; b <= 30; ++b) {
    if (L & (1<<b)) {
      ans += c[b];
      ans = min(ans, c[b+1]);
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
