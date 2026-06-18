#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 s = 0;
  cin >> n >> s;
  vector<i64> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  auto possible = [&](i64 min_level) -> bool {
    i64 can_pour = 0;
    for (int i = 0; i < n; ++i) {
      can_pour += max(v[i] - min_level, 0LL);
    }
    return can_pour >= s;
  };

  i64 l = 0, r = *min_element(v.begin(), v.end());
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
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
