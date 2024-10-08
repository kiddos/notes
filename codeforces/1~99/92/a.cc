#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  int round = (n + 1) * n / 2;
  m %= round;
  int l = 1, r = n;
  int w = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int give = (mid + 1) * mid / 2;
    if (m >= give) {
      w = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  int ans = m - (w + 1) * w / 2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
