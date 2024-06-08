#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  int mask = 1;
  int ans = n;

  for (int i = 0; i < 31; ++i) {
    if (!(n & (1<< i))) {
      int closest = (1<<i) - (n & mask);
      if (closest <= m) {
        ans |= (1<<i);
      }

      if (n > (1<<i)) {
        int masked = n & (~mask);
        closest = n - masked + 1;
        if (closest <= m) {
          ans |= (1<<i);
        }
      }
    }

    mask = mask << 1 | 1;
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
