#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int i, int j, const string& word, int index) {
    if (index == word.length()) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
    if (visited[i][j]) return false;
    if (board[i][j] != word[index]) return false;

    visited[i][j] = true;
    if (exist(board, visited, i+1, j, word, index+1)) return true;
    if (exist(board, visited, i-1, j, word, index+1)) return true;
    if (exist(board, visited, i, j+1, word, index+1)) return true;
    if (exist(board, visited, i, j-1, word, index+1)) return true;
    visited[i][j] = false;
    return false;
  }

  bool exist(vector<vector<char>>& board, const string& word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (exist(board, visited, i, j, word, 0)) return true;
      }
    }
    return false;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> board[i][j];
        cout << board[i][j];
      }
      cout << endl;
    }

    string word;
    cin >> word;
    cout << "word: " << word << endl;

    bool found = Solution().exist(board, word);
    cout << "found: " << found << endl;
  }
  return 0;
}
