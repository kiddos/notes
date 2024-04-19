#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [(0, 2, 4), (4, 6, 8), (8, 10, 12), 12, 14, 16, 16, 18]
//  6           18         30

void solve() {
  i64 n = 0;
  cin >> n;

  i64 l = 0, r = n;
  i64 g = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 triangles = mid * mid * 6;
    if (triangles <= n) {
      l = mid+1;
      g = mid;
    } else {
      r = mid-1;
    }
  }

  i64 ans = g * 3;
  i64 triangles = g * g * 6;
  i64 a0 = 4 * g;
  vector<int> d = {0, 2, 2};
  int j = 0;
  while (triangles < n) {
    a0 += d[j%3];
    triangles += a0;
    ans++;
    j++;
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
