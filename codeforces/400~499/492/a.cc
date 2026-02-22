#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  i64 ans = 0;
  i64 total = 0;
  for (i64 i = 1; i <= n; ++i) {
    total += (1 + i) * i / 2;
    if (total > n) {
      break;
    }
    ans = i;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
