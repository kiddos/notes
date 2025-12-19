#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, l = 0, x = 0, y = 0;
  cin >> n >> m >> l >> x >> y;
  vector<int> s(n), t(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> t[i];
  }
  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }

  vector<pair<int,int>> buses;
  for (int i = 0; i < n; ++i) {
    buses.push_back({s[i], t[i]});
  }
  sort(buses.begin(), buses.end());

  vector<pair<int,int>> positions;
  for (int i = 0; i < m; ++i) {
    positions.push_back({p[i], i});
  }
  sort(positions.begin(), positions.end());
  multiset<double> pool = {1e9};
  vector<double> ans(m);
  for (int i = 0, j = 0; i < m; ++i) {
    auto [pi, idx] = positions[i];
    while (j < n && buses[j].first <= pi) {
      auto [sj, tj] = buses[j];
      double t1 = (double)(tj - sj) / x;
      double t2 = (double)(l - tj) / y;
      double total = t1 + t2;
      pool.insert(total);
      j++;
    }
    double end = *pool.begin();
    ans[idx] = (double) (l - pi) / y;
    ans[idx] = min(ans[idx], end);
  }

  for (int i = 0; i < m; ++i) {
    cout << fixed << setprecision(6) << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
