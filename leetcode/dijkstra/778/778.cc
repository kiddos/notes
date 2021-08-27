#include <bits/stdc++.h>

// Swim in Rising Water
//
// just do dijkstra

using namespace std;

struct Point {
  int r, c;
  int cost;
};

struct Compare {
  bool operator()(const Point& p1, const Point& p2) {
    return p1.cost > p2.cost;
  }
};

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
    priority_queue<Point, vector<Point>, Compare> pq;
    pq.push(Point{0, 0, grid[0][0]});
    dist[0][0] = grid[0][0];
    vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!pq.empty()) {
      auto point = pq.top();
      pq.pop();
      if (point.r == m - 1 && point.c == n - 1) break;
      for (vector<int>& d : delta) {
        int r2 = point.r + d[0], c2 = point.c + d[1];
        if (r2 < 0 || r2 >= m || c2 < 0 || c2 >= n) continue;
        int cost = max(point.cost, grid[r2][c2]);
        if (cost < dist[r2][c2]) {
          dist[r2][c2] = cost;
          pq.push(Point{r2, c2, cost});
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                              {24, 23, 22, 21, 5},
                              {12, 13, 14, 15, 16},
                              {11, 17, 18, 19, 20},
                              {10, 9, 8, 7, 6}};
  int ans = Solution().swimInWater(grid);
  assert(ans == 16);

  return 0;
}
