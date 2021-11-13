#include <bits/stdc++.h>

using namespace std;

// Sliding Puzzle
//
// this is just bfs implementation

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    function<int(vector<vector<int>>&)> create_state =
        [&](vector<vector<int>>& b) {
          int p = 0;
          for (int k = 0; k < 6; ++k) p = p * 10 + b[k / 3][k % 3];
          return p;
        };

    function<vector<int>(int)> possible_slides = [&](int state) {
      vector<vector<int>> b(2, vector<int>(3));
      int r = 0, c = 0;
      for (int i = 0; i < 6; ++i) {
        int k = 6 - i - 1;
        int p = k / 3, q = k % 3;
        b[p][q] = state % 10;
        state /= 10;
        if (b[p][q] == 0) {
          r = p;
          c = q;
        }
      }
      /*
      for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 3; ++j) {
              cout << b[i][j] << " ";
          }
          cout << endl;
      }
      cout << r << ", " << c << endl;
      */
      vector<int> possible;
      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= 2 || c2 < 0 || c2 >= 3) continue;
        swap(b[r][c], b[r2][c2]);
        possible.push_back(create_state(b));
        swap(b[r][c], b[r2][c2]);
      }
      return possible;
    };

    int steps = 0;
    unordered_set<int> visited;
    queue<int> q;
    q.push(create_state(board));
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int state = q.front();
        if (state == 123450) return steps;
        q.pop();
        for (int next_state : possible_slides(state)) {
          // cout << next_state << endl;
          if (!visited.count(next_state)) {
            visited.insert(next_state);
            q.push(next_state);
          }
        }
      }
      steps++;
    }
    return -1;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
  int ans = Solution().slidingPuzzle(board);
  assert(ans == 1);

  board = {{1, 2, 3}, {5, 4, 0}};
  ans = Solution().slidingPuzzle(board);
  assert(ans == -1);

  board = {{4, 1, 2}, {5, 0, 3}};
  ans = Solution().slidingPuzzle(board);
  assert(ans == 5);

  board = {{3, 2, 4}, {1, 5, 0}};
  ans = Solution().slidingPuzzle(board);
  assert(ans == 14);

  return 0;
}
