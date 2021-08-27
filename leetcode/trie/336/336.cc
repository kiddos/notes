#include <bits/stdc++.h>

using namespace std;

// Palindrome Pairs
//
// insert words into trie backwards
// 1. when search the word from front, if found a word before and the word is not itself
// (eg, it->index != index) and if the rest of this word is a palindrome then
// this is part of the answer
// example.
// "a" is in trie
// search "abcb" and "a" is in the trie and "bcb" is palindrome, this is a pair
//
// 2. we also need to check if the other word in trie can be insert at the front like
// "a" and "bcba"
// when "bcba" is in the trie and search for "a", this needs to be part of the answer
// -> we need to compute if the prefix is palindrome
// -> if we can find words from backwards and the prefix is a palindrome,
// add this to the answer

struct TrieNode {
  TrieNode* children[26];
  int index;
  vector<int> palindrome;

  TrieNode() : children{nullptr}, index(-1) {}
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      if (children[i]) delete children[i];
    }
  }
};

bool is_palindrome(const string& word, int l, int r) {
  while (l < r) {
    if (word[l++] != word[r--]) return false;
  }
  return true;
}

void insert(TrieNode* root, const string& word, int index) {
  TrieNode* it = root;
  int n = word.length();
  for (int i = n - 1; i >= 0; --i) {
    char c = word[i];
    if (is_palindrome(word, 0, i)) it->palindrome.push_back(index);
    if (!it->children[c - 'a']) it->children[c - 'a'] = new TrieNode();
    it = it->children[c - 'a'];
  }
  it->index = index;
  it->palindrome.push_back(index);
}

void search(TrieNode* root, const string& word, int index,
            vector<vector<int>>& ans) {
  int n = word.length();
  TrieNode* it = root;
  for (int i = 0; i < n; ++i) {
    if (it->index >= 0 && it->index != index && is_palindrome(word, i, n - 1)) {
      ans.push_back({index, it->index});
    }
    if (!it->children[word[i] - 'a']) return;
    it = it->children[word[i] - 'a'];
  }
  for (int j : it->palindrome) {
    if (j == index) continue;
    ans.push_back({index, j});
  }
}

class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    unique_ptr<TrieNode> root(new TrieNode());
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      insert(root.get(), words[i], i);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
      search(root.get(), words[i], i, ans);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> ans = Solution().palindromePairs(words);
  for (vector<int>& p : ans) {
    string s = words[p[0]] + words[p[1]];
    assert(is_palindrome(s, 0, s.length()-1));
  }
  return 0;
}
