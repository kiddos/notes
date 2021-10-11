#include <bits/stdc++.h>

using namespace std;

// Word Search II
//
// the idea is to use build the trie with the input words
// and use this trie to skip as much as possible when doing backtracking

struct TrieNode {
  TrieNode* children[26];
  int index;

  TrieNode() : children{nullptr}, index(-1) {}
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      if (children[i]) delete children[i];
    }
  }
};

void insert(TrieNode* root, const string& word, int index) {
  TrieNode* it = root;
  for (char c : word) {
    if (!it->children[c - 'a']) it->children[c - 'a'] = new TrieNode();
    it = it->children[c - 'a'];
  }
  it->index = index;
}

void search(TrieNode* node, vector<vector<char>>& board, int i, int j,
            vector<vector<bool>>& visited, vector<vector<int>>& delta,
            unordered_set<int>& indices) {
  char c = board[i][j];
  TrieNode* next_node = node->children[c - 'a'];
  if (!next_node) return;
  if (next_node->index >= 0) {
    indices.insert(next_node->index);
  }

  visited[i][j] = true;
  for (vector<int>& d : delta) {
    int i2 = i + d[0], j2 = j + d[1];
    if (i2 < 0 || i2 >= board.size() || j2 < 0 || j2 >= board[0].size() ||
        visited[i2][j2])
      continue;
    search(next_node, board, i2, j2, visited, delta, indices);
  }
  visited[i][j] = false;
}

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    unique_ptr<TrieNode> root(new TrieNode());
    for (int i = 0; i < words.size(); ++i) insert(root.get(), words[i], i);

    vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_set<int> indices;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        search(root.get(), board, i, j, visited, delta, indices);
      }
    }
    vector<string> ans;
    for (int idx : indices) {
      ans.push_back(words[idx]);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<string> ans = Solution().findWords(board, words);
  for (string a : ans) cout << a << endl;
  return 0;
}
