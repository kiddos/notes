#include <bits/stdc++.h>

using namespace std;


struct TrieNode {
  TrieNode* children[256];
  bool end;

  TrieNode() : children{nullptr}, end(false) {}
};

class WordDictionary {
 public:
  WordDictionary() : root_(new TrieNode) {}

  ~WordDictionary() {
    cleanup(root_);
  }

  void cleanup(TrieNode* root) {
    if (root) {
      for (int i = 0; i < 256; ++i) {
        cleanup(root->children[i]);
      }
      delete root;
    }
  }

  void addWord(const string& word) {
    TrieNode* it = root_;
    for (unsigned char c : word) {
      if (!it->children[c]) it->children[c] = new TrieNode();
      it = it->children[c];
    }
    it->end = true;
  }

  bool search(const string& word) {
    return search(root_, word);
  }

 private:
  TrieNode* root_;

  bool search(TrieNode* root, const string& word) {
    TrieNode* it = root;
    for (int i = 0; i < word.length(); ++i) {
      unsigned char c = word[i];
      if (c == '.') {
        string suffix = word.substr(i+1);
        for (int j = 0; j < 256; ++j) {
          if (it->children[j] && search(it->children[j], suffix))
            return true;
        }
        return false;
      } else {
        if (!it->children[c]) return false;
        it = it->children[c];
      }
    }
    return it->end;
  }
};


int main(void) {
  WordDictionary wd;
  wd.addWord("bad");
  wd.addWord("dad");
  wd.addWord("mad");
  cout << wd.search("pad") << endl;
  cout << wd.search("bad") << endl;
  cout << wd.search(".ad") << endl;
  cout << wd.search("b..") << endl;
  return 0;
}
