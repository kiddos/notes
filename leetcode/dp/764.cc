#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    vector<vector<int>> grid(N, vector<int>(N, 1));
    for (vector<int>& mine : mines) {
      grid[mine[0]][mine[1]] = 0;
    }

    vector<vector<int>> left(N, vector<int>(N));
    vector<vector<int>> right(N, vector<int>(N));
    vector<vector<int>> top(N, vector<int>(N));
    vector<vector<int>> bottom(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j]) {
          left[i][j] = j > 0 ? left[i][j-1]+1 : 1;
          top[i][j] = i > 0 ? top[i-1][j]+1 : 1;
        }
      }
    }
    int ans = 0;
    for (int i = N-1; i >= 0; --i) {
      for (int j = N-1; j >= 0; --j) {
        if (grid[i][j]) {
          right[i][j] = j < N-1 ? right[i][j+1]+1 : 1;
          bottom[i][j] = i < N-1 ? bottom[i+1][j]+1 : 1;
        }

        int size = min({left[i][j], right[i][j], top[i][j], bottom[i][j]});
        ans = max(ans, size);
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> mines = {{4, 2}};
  int N = 5;
  int ans = Solution().orderOfLargestPlusSign(N, mines);
  assert(ans == 2);
  return 0;
}
