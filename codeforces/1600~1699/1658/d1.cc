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

constexpr int MAX_BIT = 17;

void insert(TrieNode* root, int x) {
  TrieNode* it = root;
  for (int i = MAX_BIT; i >= 0; --i) {
    int b = (x & (1<<i)) ? 1 : 0;
    if (!it->children[b]) {
      it->children[b] = new TrieNode();
    }
    it = it->children[b];
  }
  it->count++;
}

int find_max(TrieNode* node, int x, int i, int y) {
  if (i < 0) {
    return y ^ x;
  }

  int b = x & (1<<i) ? 0 : 1;
  if (node->children[b]) {
    return find_max(node->children[b], x, i-1, y | (b << i));
  } else {
    return find_max(node->children[1-b], x, i-1, y | ((1-b) << i));
  }
}

int find_min(TrieNode* node, int x, int i, int y) {
  if (i < 0) {
    return y ^ x;
  }

  int b = x & (1<<i) ? 1 : 0;
  if (node->children[b]) {
    return find_min(node->children[b], x, i-1, y | (b << i));
  } else {
    return find_min(node->children[1-b], x, i-1, y | ((1-b) << i));
  }
}

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  int n = r-l+1;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n % 2 == 1) {
    int x = 0;
    for (int i = 0; i < n; ++i) x ^= a[i];
    for (int i = l; i <= r; ++i) x ^= i;
    cout << x << endl;
  } else {
    unique_ptr<TrieNode> root(new TrieNode());
    for (int i = 0; i < n; ++i) {
      insert(root.get(), a[i]);
    }

    for (int i = 0; i < n; ++i) {
      int x = a[i] ^ l;
      int max_val = find_max(root.get(), x, MAX_BIT, 0);
      int min_val = find_min(root.get(), x, MAX_BIT, 0);
      // cout << max_val << ", " << min_val << endl;
      if (max_val == r && min_val == l) {
        cout << x << endl;
        return;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
