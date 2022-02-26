#include <bits/stdc++.h>

using namespace std;

constexpr int K = 26;

struct TrieNode {
  TrieNode* children[K];
  TrieNode* failure;
  unordered_set<int> index;

  TrieNode() : children{nullptr}, failure(nullptr) {}
  ~TrieNode() {
    for (int i = 0; i < K; ++i) if (children[i] != this) delete children[i];
  }
};

void add_string(TrieNode* root, const string& word, int index)  {
  TrieNode* it = root;
  for (char ch : word) {
    int c = ch-'a';
    if (!it->children[c]) it->children[c] = new TrieNode();
    it = it->children[c];
  }
  it->index.insert(index);
}

void aho_corasick(TrieNode* root) {
  root->failure = root;
  queue<TrieNode*> q;
  for (int i = 0; i < K; ++i) {
    if (root->children[i]) {
      root->children[i]->failure = root;
      q.push(root->children[i]);
    } else {
      root->children[i] = root;
    }
  }

  while (!q.empty()) {
    TrieNode* node = q.front();
    q.pop();
    for (int i = 0; i < K; ++i) {
      if (node->children[i]) {
        TrieNode* f = node->failure;
        while (!f->children[i]) f = f->failure;

        f = f->children[i];
        node->children[i]->failure = f;
        if (f != node->children[i]) {
          for (int idx : f->index) {
            node->children[i]->index.insert(idx);
          }
        }
        q.push(node->children[i]);
      }
    }
  }
}

unordered_set<int> find(TrieNode** node, char ch) {
  int c = ch - 'a';
  while (!(*node)->children[c]) {
    *node = (*node)->failure;
  }
  *node = (*node)->children[c];
  return (*node)->index;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  unique_ptr<TrieNode> root(new TrieNode());
  vector<string> words = {"ab", "ba", "aaab", "abab", "baa"};
  for (int i = 0; i < words.size(); ++i) {
    add_string(root.get(), words[i], i);
  }
  aho_corasick(root.get());

  string query = "aaaaabababbbababbbbababaaabaaa";
  TrieNode* r = root.get();
  unordered_set<string> found;
  for (char c : query) {
    unordered_set<int> indices = find(&r, c);
    for (int i : indices) found.insert(words[i]);
  }
  for (string s : found) cout << s << " ";
  cout << endl;
  return 0;
}
