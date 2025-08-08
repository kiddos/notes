#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,2>> points;
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    points.push_back({x, y});
  }

  vector<int> indices(n);
  iota(indices.begin(), indices.end(), 0);
  sort(indices.begin(), indices.end(), [&](int i1, int i2) {
    return points[i1][0] < points[i2][0];
  });
  int m = n/2;
  sort(indices.begin(), indices.begin() + m, [&](int i1, int i2) {
    return points[i1][1] < points[i2][1];
  });
  sort(indices.begin() + m, indices.end(), [&](int i1, int i2) {
    return points[i1][1] < points[i2][1];
  });


  vector<pair<int,int>> ans;
  for (int l = 0, r = n-1; l < m; ++l, --r) {
    ans.emplace_back(indices[l], indices[r]);
  }
  // int total = 0;
  for (auto [i1, i2] : ans) {
    cout << i1+1 << " " << i2+1 << endl;
    // total += abs(points[i1][0] - points[i2][0]) + abs(points[i1][1] - points[i2][1]);
  }
  // cout << total << endl;
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
