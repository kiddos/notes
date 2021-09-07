#include <bits/stdc++.h>

using namespace std;

// gift_wrapping algorithm is one of the algorithm for solving convex hull
// idea:
// 1. find the left most point
// 2. find a point in the rest of the points
// such that there is no points on the left side of the
// line segment of this point and the last point
// 3. also include the point on the line segment
// 4. repeat this until the next point is the starting point

int cross_product(const pair<int, int>& a, const pair<int, int>& b,
                  const pair<int, int>& c) {
  const pair<int, int> ab = {a.first - b.first, a.second - b.second};
  const pair<int, int> ac = {a.first - c.first, a.second - c.second};
  return ab.first * ac.second - ab.second * ac.first;
}

vector<pair<int, int>> gift_wrapping(vector<pair<int, int>>& points) {
  sort(points.begin(), points.end());

  int n = points.size();
  set<pair<int, int>> s;
  pair<int, int> first = points[0];
  pair<int, int> current = first;
  s.insert(first);
  while (true) {
    pair<int, int> next_point = points[0];
    vector<pair<int, int>> linear;
    int far = abs(next_point.first - current.first) +
              abs(next_point.second - current.second);
    for (int i = 1; i < n; ++i) {
      const int cp = cross_product(current, next_point, points[i]);
      if (cp > 0) {
        next_point = points[i];
        linear = {points[i]};
      } else if (cp == 0) {
        int dist = abs(points[i].first - current.first) +
                   abs(points[i].second - current.second);
        if (dist > far) {
          far = dist;
          next_point = points[i];
        }
        linear.push_back(points[i]);
      }
    }

    for (auto& l : linear) s.insert(l);

    current = next_point;
    if (current == first) break;
  }
  return vector<pair<int, int>>(s.begin(), s.end());
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<pair<int, int>> points = {{1, 1}, {2, 2}, {2, 0},
                                   {2, 4}, {3, 3}, {4, 2}};
  vector<pair<int, int>> ans = gift_wrapping(points);
  for (auto a : ans) cout << a.first << ", " << a.second << "  ";
  cout << endl;

  points = {{1, 2}, {2, 2}, {4, 2}};
  ans = gift_wrapping(points);
  for (auto a : ans) cout << a.first << ", " << a.second << "  ";
  cout << endl;

  points = {{0, 0}, {0, 100}, {100, 100}, {100, 0}};
  ans = gift_wrapping(points);
  for (auto a : ans) cout << a.first << ", " << a.second << "  ";
  cout << endl;

  return 0;
}
