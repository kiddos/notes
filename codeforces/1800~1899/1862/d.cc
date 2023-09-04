#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 find_balls(i64 n) {
  i64 l = 2, r = 2e9;
  i64 ans = l;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (mid * (mid-1) / 2 <= n) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  return ans;
}

void solve() {
  i64 n = 0;
  cin >> n;
  if (n == 2) {
    cout << "3" << endl;
    return;
  }

  i64 balls = find_balls(n);
  i64 types = balls * (balls-1) / 2;
  i64 num = n / types;
  i64 ans = num * balls;
  ans += n % types;

  // cout << "balls=" << balls << endl;

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
