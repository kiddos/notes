#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> field(n);
  for (int i = 0; i < n; ++i) cin >> field[i];

  auto process = [&](int offset) -> int {
    vector<pair<int,int>> points;
    for (int c = 0; c < m; ++c) {
      for (int r = offset ^ (c % 2); r < n; r += 2) {
        if (field[r][c] == '1') {
          points.emplace_back(c+r, r-c);
        }
      }
    }

    sort(points.begin(), points.end());
    multiset<int> s;
    for (auto p : points) {
      auto it = s.upper_bound(p.second);
      if (it == s.begin()) {
        s.insert(p.second);
      } else {
        s.erase(--it);
        s.insert(p.second);
      }
    }
    return s.size();
  };

  int ans = process(0) + process(1);
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
