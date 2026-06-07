#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, pos = 0, l = 0, r = 0;
  cin >> n >> pos >> l >> r;
  int ans = 0;
  if (l > 1 && r < n) {
    if (pos < l) {
      // to the left
      ans = (r - pos) + 2;
    } else if (pos > r) {
      // to the right
      ans = (pos - l) + 2;
    } else {
      // middle
      ans = min(pos - l, r - pos) + r - l + 2;
    }
  } else if (l > 1) {
    if (pos < l) {
      ans = l - pos + 1;
    } else {
      ans = pos - l + 1;
    }
  } else if (r < n) {
    if (pos > r) {
      ans = pos - r + 1;
    } else {
      ans = r - pos + 1;
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
