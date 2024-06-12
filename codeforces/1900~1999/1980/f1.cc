#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<pair<int,int>> points(k);
  for (int i = 0; i < k; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  vector<pair<int,int>> p = points;
  sort(p.begin(), p.end());
  map<int, int> col_min;
  for (int i = 0; i < k; ++i) {
    auto [r, c] = p[i];
    if (col_min.count(r)) {
      col_min[r] = min(col_min[r], c);
    } else {
      col_min[r] = c;
    }
  }

  vector<pair<int,int>> key_points;
  for (auto& [r, c] : col_min) {
    while (!key_points.empty() && key_points.back().second >= c) {
      key_points.pop_back();
    }

    key_points.push_back({r, c});
  }

  set<pair<int,int>> pool;
  i64 last = 0;
  i64 bob = 0;
  for (auto& [r, c] : key_points) {
    i64 h = r - last;
    i64 w = m - c + 1;
    bob += h * w;
    last = r;
    pool.insert({r, c});
  }

  i64 alice = (i64)m * n - bob;
  cout << alice << endl;

  vector<int> ans(k);
  for (int i = 0; i < k; ++i) {
    if (pool.count(points[i])) {
      ans[i] = 1;
    }
  }
  for (int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
