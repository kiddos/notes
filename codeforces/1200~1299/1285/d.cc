#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[2];
  bool end;

  TrieNode() : children{nullptr}, end(false) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) {
      delete children[i];
    }
  }
};

void insert(TrieNode* root, int x) {
  TrieNode* it = root;
  for (int b = 30; b >= 0; --b) {
    int bit = (x & (1<<b)) ? 1 : 0;
    if (!it->children[bit]) {
      it->children[bit] = new TrieNode();
    }
    it = it->children[bit];
  }
  it->end = true;
}

int search(TrieNode* node, int bit, int value) {
  if (bit < 0) {
    return value;
  }
  if (node->children[0] && node->children[1]) {
    return min(search(node->children[0], bit-1, value | (1<<bit)),
               search(node->children[1], bit-1, value | (1<<bit)));
  } else if (node->children[0]) {
    return search(node->children[0], bit-1, value);
  } else if (node->children[1]) {
    return search(node->children[1], bit-1, value);
  } else {
    return numeric_limits<int>::max();
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  unique_ptr<TrieNode> root(new TrieNode());
  for (int i = 0; i < n; ++i) {
    insert(root.get(), a[i]);
  }
  int ans = search(root.get(), 30, 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
