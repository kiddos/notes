#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  int l = 0, r = k;
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    i64 row = m / (mid+1) * mid;
    int left = m % (mid + 1);
    row += left;

    i64 total = row * n;
    if (total >= k) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
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
