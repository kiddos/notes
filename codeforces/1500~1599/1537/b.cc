#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, i = 0, j = 0;
  cin >> n >> m >> i >> j;

  auto compute_dist = [&](pair<i64,i64>& c1, pair<i64,i64>& c2) -> i64 {
    i64 dist = abs(i - c1.first) + abs(j - c1.second);
    dist += abs(c1.first - c2.first) + abs(c1.second - c2.second);
    dist += abs(c2.first - i) + abs(c2.second - j);
    return dist;
  };

  set<pair<i64,i64>> s;
  s.insert({1, 1});
  s.insert({1, m});
  s.insert({n, 1});
  s.insert({n, m});

  vector<pair<i64,i64>> corners(s.begin(), s.end());
  int size = corners.size();
  array<i64, 4> ans;
  i64 best = -1;
  for (int a = 0; a < size; ++a) {
    for (int b = 0; b < size; ++b) {
      i64 dist = compute_dist(corners[a], corners[b]);
      if (dist > best) {
        best = dist;
        ans = {corners[a].first, corners[a].second, corners[b].first, corners[b].second};
      }
      // cout << dist << endl;
    }
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
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
