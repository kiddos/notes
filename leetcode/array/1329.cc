#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> pq;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        pq[i-j].push(mat[i][j]);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = pq[i-j].top();
        pq[i-j].pop();
      }
    }
    return mat;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> mat = { { 3,3,1,1 },{ 2,2,1,2 },{ 1,1,1,2 } };
  vector<vector<int>> ans = Solution().diagonalSort(mat);
  vector<vector<int>> target = { { 1,1,1,1 },{ 1,2,2,2 },{ 1,2,3,3 } };
  int m = ans.size(), n = ans[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      assert(target[i][j] == ans[i][j]);
    }
  };

  return 0;
}


