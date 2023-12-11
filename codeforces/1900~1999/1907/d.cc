#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<i64, 2>> segments;
  for (int i = 0; i < n; ++i) {
    i64 l = 0, r = 0;
    cin >> l >> r;
    segments.push_back({l, r});
  }

  auto intersect = [&](i64 s1, i64 e1, i64 s2, i64 e2) -> array<i64, 2> {
    return {max(s1, s2), min(e1, e2)};
  };

  auto possible = [&](i64 k) -> bool {
    array<i64, 2> s = {0, 0};
    for (int i = 0; i < n; ++i) {
      array<i64, 2> s2 = intersect(s[0]-k, s[1]+k, segments[i][0], segments[i][1]);
      if (s2[0] > s2[1]) {
        return false;
      } else {
        s = move(s2);
      }
    }
    return true;
  };

  i64 l = 0, r = numeric_limits<i64>::max();
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
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
