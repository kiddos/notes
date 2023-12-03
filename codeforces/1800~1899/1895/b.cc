#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = 2 * n;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  vector<pair<int,int>> points;
  for (int i = 0; i < n; ++i) {
    points.emplace_back(a[i], a[i+n]);
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += points[i].first - points[i-1].first;
    ans += points[i].second - points[i-1].second;
  }

  cout << ans << endl;
  for (int i = 0;i < n; ++i) {
    cout << points[i].first << " " << points[i].second << endl;
  }
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
