#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

template <int NODE_SIZE>
struct GenericTrieNode {
  GenericTrieNode* children[NODE_SIZE];
  int count;

  GenericTrieNode() : children{nullptr}, count(0) {}
  ~GenericTrieNode() {
    for (int i = 0; i < NODE_SIZE; ++i) {
      delete children[i];
    }
  }
};

using TrieNode = GenericTrieNode<26>;

void insert(TrieNode* root, const string& s) {
  TrieNode* it = root;
  root->count++;
  for (char ch : s) {
    int c = ch - 'a';
    if (!it->children[c]) {
      it->children[c] = new TrieNode();
    }
    it = it->children[c];
    it->count++;
  }
}

TrieNode* remove_node(TrieNode* node, const string& s, int i) {
  if (!node) {
    return nullptr;
  }

  if (--node->count == 0) {
    delete node;
    return nullptr;
  }

  if (i == (int)s.length()) {
    delete node;
    return nullptr;
  }

  int c = s[i] - 'a';
  node->children[c] = remove_node(node->children[c], s, i+1);
  return node;
}

void remove(TrieNode* root, const string& s) {
  remove_node(root, s, 0);
}

bool query(TrieNode* root, const string& prefix) {
  TrieNode* it = root;
  for (char ch : prefix) {
    int c = ch-'a';
    if (!it->children[c]) {
      return false;
    }
    it = it->children[c];
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> strs = {"apple", "banana", "watermelon", "awesome"};
  unique_ptr<TrieNode> root(new TrieNode());
  for (string& s : strs) {
    insert(root.get(), s);
  }

  assert(query(root.get(), "app"));
  assert(query(root.get(), "ba"));
  assert(query(root.get(), "water"));
  assert(query(root.get(), "awe"));

  remove(root.get(), "apple");

  assert(!query(root.get(), "app"));
  assert(query(root.get(), "a"));
  return 0;
}
