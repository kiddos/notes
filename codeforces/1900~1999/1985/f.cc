#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, n = 0;
  cin >> h >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  auto can_kill_boss = [&](i64 turns) -> bool {
    i64 damage = 0;
    for (int i = 0; i < n; ++i) {
      i64 attacks = (turns - 1) / c[i] + 1;
      damage += attacks * a[i];
    }
    return damage >= h;
  };

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 max_attacks = (h + sum - 1) / sum;
  i64 l = 1, r = max_attacks * (*max_element(c.begin(), c.end()) + 1);
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (can_kill_boss(mid)) {
      ans = mid;
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

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
