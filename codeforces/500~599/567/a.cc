#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({x[i], i});
  }
  sort(p.begin(), p.end());
  vector<pair<int,int>> ans(n);
  for (int i = 0; i < n; ++i) {
    int max_dist = max(p[i].first - p[0].first, p.back().first - p[i].first);
    int min_dist = numeric_limits<int>::max();
    if (i > 0) {
      min_dist = min(min_dist, p[i].first - p[i-1].first);
    }
    if (i+1 < n) {
      min_dist = min(min_dist, p[i+1].first - p[i].first);
    }
    ans[p[i].second] = {min_dist, max_dist};
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
