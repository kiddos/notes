#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;

  if (m > n) {
    cout << n << endl;
    return;
  }

  i64 l = 0, r = 2e9;
  n -= m;
  i64 ans = m+r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 total = mid * (mid+1) / 2;
    if (total >= n) {
      ans = mid + m;
      r = mid-1;
    } else {
      l = mid+1;
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
