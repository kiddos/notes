#include <bits/stdc++.h>

using namespace std;

// Trapping Rain Water II
//
// the first intuition is to use DP like for the 1D case
// However, that will produce wrong answer
// if we look at this case:
// [[12,13,1,12],
//  [13,4,13,12],
//  [13,8,10,12],
//  [12,13,12,12],
//  [13,13,13,13]]
//
//  the water at 4 will leak out at height 12 not 13
// so basically the problem becomes finding the "min path" for each cell to get
// to the border the "min path" value is defined to be the max value of the path

struct Cell {
  int r, c;
  int height;
};

struct CompareCell {
  bool operator()(const Cell& c1, const Cell& c2) {
    return c1.height > c2.height;
  }
};

class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    priority_queue<Cell, vector<Cell>, CompareCell> pq;
    vector<vector<int>> min_path(m, vector<int>(n, numeric_limits<int>::max()));
    for (int i = 0; i < m; ++i) {
      pq.push(Cell{i, 0, heightMap[i][0]});
      pq.push(Cell{i, n - 1, heightMap[i][n - 1]});
      min_path[i][0] = heightMap[i][0];
      min_path[i][n - 1] = heightMap[i][n - 1];
    }
    for (int j = 0; j < n; ++j) {
      pq.push(Cell{0, j, heightMap[0][j]});
      pq.push(Cell{m - 1, j, heightMap[m - 1][j]});
      min_path[0][j] = heightMap[0][j];
      min_path[m - 1][j] = heightMap[m - 1][j];
    }

    vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!pq.empty()) {
      auto [r, c, height] = pq.top();
      pq.pop();
      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= m || c2 < 0 || c2 >= n) continue;
        if (height < min_path[r2][c2]) {
          min_path[r2][c2] = height;
          pq.push(Cell{r2, c2, max(height, heightMap[r2][c2])});
        }
      }
    }
    /*
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << min_path[i][j] << " ";
        }
        cout << endl;
    }
    */

    int ans = 0;
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        ans += max(min_path[i][j] - heightMap[i][j], 0);
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> heightMap = {{12, 13, 1, 12},
                                   {13, 4, 13, 12},
                                   {13, 8, 10, 12},
                                   {12, 13, 12, 12},
                                   {13, 13, 13, 13}};
  int ans = Solution().trapRainWater(heightMap);
  assert(ans == 14);

  heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
  ans = Solution().trapRainWater(heightMap);
  assert(ans == 4);

  heightMap = {{3, 3, 3, 3, 3},
               {3, 2, 2, 2, 3},
               {3, 2, 1, 2, 3},
               {3, 2, 2, 2, 3},
               {3, 3, 3, 3, 3}};
  ans = Solution().trapRainWater(heightMap);
  assert(ans == 10);

  return 0;
}
