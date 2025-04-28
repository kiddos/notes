#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int inf = 1000000000;

struct TrieNode {
  TrieNode* children[2];
  int max_index;
  TrieNode() : children{nullptr}, max_index(-1) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) {
      delete children[i];
    }
  }
};

void insert(TrieNode* root, int x, int idx) {
  TrieNode* it = root;
  for (int i = 30; i >= 0; --i) {
    int b = x & (1<<i) ? 1 : 0;
    if (!it->children[b]) {
      it->children[b] = new TrieNode();
    }
    it = it->children[b];
    it->max_index = idx;
  }
}

// k | x y
// 0 | 0 y
// 0 | 1 y
// 1 | 0 n
// 1 | 1 y

int search(TrieNode* node, int b, int x, int k, bool greater) {
  if (!node) {
    return -1;
  }
  if (b < 0) {
    return node->max_index;
  }
  if (greater) {
    return node->max_index;
  }

  int bk = k & (1<<b);
  int bx = x & (1<<b);
  int bit = bx ? 0 : 1;
  // cout << "k[" << b<< "]=" << (bk ? 1 : 0)<< endl;
  if (bk) {
    return search(node->children[bit], b-1, x, k, greater);
  } else {
    if (bx) {
      return max(
        search(node->children[0], b-1, x, k, true),
        search(node->children[1], b-1, x, k, false)
      );
    } else {
      return max(
        search(node->children[0], b-1, x, k, false),
        search(node->children[1], b-1, x, k, true)
      );
    }
  }
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  unique_ptr<TrieNode> root(new TrieNode());
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    insert(root.get(), a[i], i);
    int idx = search(root.get(), 30, a[i], k, false);
    // cout << "i=" << i << ", idx=" << idx << endl;
    if (idx >= 0) {
      int len = i-idx+1;
      ans = min(ans, len);
    }
  }
  if (ans < inf) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
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
