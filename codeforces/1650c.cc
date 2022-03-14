#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, w, index;
};

struct ComparePoints {
  bool operator()(const Point& p1, const Point& p2) const {
    return p1.w < p2.w;
  }
};

int solve(vector<Point>& points, int n, vector<pair<int, int>>& pairs) {
  sort(points.begin(), points.end(), [&](auto& p1, auto& p2) {
    return p1.w < p2.w;
  });

  sort(points.begin(), points.begin() + 2 * n, [&](auto& p1, auto& p2) {
    return p1.x < p2.x;
  });

  int total = 0;
  for (int i = 0, j = 2*n-1; i < n; ++i, --j) {
    total += points[i].w;
    total += points[j].w;
    pairs.push_back({points[i].index, points[j].index});
  }
  return total;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
      cin >> points[i].x >> points[i].w;
      points[i].index = i+1;
    }
    vector<pair<int,int>> pairs;
    int ans = solve(points, n, pairs);
    cout << ans << '\n';
    for (auto [x1, x2] : pairs) {
      cout << x1 << ' ' << x2 << '\n';
    }
    cout << '\n';
  }
  cout << flush;
  return 0;
}
