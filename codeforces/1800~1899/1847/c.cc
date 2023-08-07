#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
  TrieNode* children[2];
  bool end;
  TrieNode() : children{nullptr}, end(false) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) delete children[i];
  }
};

void insert(TrieNode* root, int x) {
  TrieNode* it = root;
  for (int b = 7; b >= 0; --b) {
    int d = (x & (1<<b)) ? 1 : 0;
    if (!it->children[d]) it->children[d] = new TrieNode();
    it = it->children[d];
  }
  it->end = true;
}

int find(TrieNode* root, int b, int val, int x) {
  if (b < 0) return val;
  int d = (x & (1<<b)) ? 0 : 1;
  if (root->children[d]) {
    return find(root->children[d], b-1, val | (d << b), x);
  }
  return find(root->children[1-d], b-1, val | ((1-d) << b), x);
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  unique_ptr<TrieNode> root(new TrieNode());
  insert(root.get(), 0);

  int ans = *max_element(a.begin(), a.end());
  int x = 0;
  for (int i = 0; i < n; ++i) {
    x ^= a[i];
    int p = find(root.get(), 7, 0, x);
    ans = max(ans, x ^ p);
    insert(root.get(), x);
  }

  cout << ans << endl;
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
