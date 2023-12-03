#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[2];
  int count;

  TrieNode() : children{nullptr}, count(0) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) delete children[i];
  }
};

constexpr int BIT = 20;

void insert(TrieNode* root, int x) {
  TrieNode* node = root;
  for (int i = BIT; i >= 0; --i) {
    int b = (x & (1<<i)) ? 1 : 0;
    if (!node->children[b]) node->children[b] = new TrieNode();
    node = node->children[b];
  }
  node->count++;
}

int find_max(TrieNode* root, int b0) {
  TrieNode* node = root;
  int x = 0;
  for (int i = BIT; i >= 0; --i) {
    int b = b0 & (1<<i);
    if (b) {
      if (node->children[0]) {
        node = node->children[0];
      } else {
        node = node->children[1];
        x |= (1<<i);
      }
    } else {
      if (node->children[1]) {
        x |= (1<<i);
        node = node->children[1];
      } else {
        node = node->children[0];
      }
    }
  }
  return x;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; ++i) cin >> a[i];

  vector<int> p = a;
  for (int i = 2; i < n; ++i) {
    p[i] = p[i-1] ^ p[i];
  }

  unique_ptr<TrieNode> root(new TrieNode());
  for (int i = 1; i < n; ++i) {
    insert(root.get(), p[i]);
  }

  for (int b0 = 0; b0 < n; ++b0) {
    int p = find_max(root.get(), b0);
    int x = p ^ b0;
    // cout << "p=" << p << ", x=" << x << endl;
    if (x < n) {
      int b = b0;
      cout << b << " ";
      for (int i = 1; i < n; ++i) {
        b = b ^ a[i];
        cout << b << " ";
      }
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
