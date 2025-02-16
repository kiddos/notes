#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<pair<int,int>> points;
  for (int i = 0; i < n; ++i) {
    points.emplace_back(r[i], c[i]);
  }
  sort(points.begin(), points.end());

  pair<int,int> current = {1, 1};
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [ri, ci] = points[i];
    if ((current.first - current.second) / 2 == (ri - ci) / 2) {
      if ((current.first - current.second) % 2 == 0 && (ri - ci) % 2 == 0) {
        ans += ri - current.first;
      }
    } else {
      ans += (ri - ci) / 2 - (current.first - current.second) / 2;
    }

    current = {ri, ci};
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
