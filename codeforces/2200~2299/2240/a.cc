#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int left = n;
  int ans = 0;
  for (int b = 0; b < 32; ++b) {
    int val = 1<<b;
    int can_take = min(left / val, k);
    left -= can_take * val;
    ans += can_take;
  }
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
