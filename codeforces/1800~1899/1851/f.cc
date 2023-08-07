#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[2];
  int index;

  TrieNode() : children{nullptr}, index(-1) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) delete children[i];
  }
};

void insert(TrieNode* root, int x, int idx, int k) {
  TrieNode* it = root;
  for (int i = k-1; i >= 0; --i) {
    int b = (x & (1<<i)) ? 1 : 0;
    if (!it->children[b]) it->children[b] = new TrieNode();
    it = it->children[b];
  }
  it->index = idx;
}

array<int,3> find_most_match(TrieNode* root, int num, int k) {
  int y = 0, x = 0;
  TrieNode* it = root;
  for (int i = k-1; i >= 0; --i) {
    int b = (num & (1<<i)) ? 1 : 0;
    if (it->children[b]) {
      x |= ((1-b) << i);
      y |= (1 << i);
      it = it->children[b];
    } else {
      it = it->children[1-b];
    }
  }
  return {it->index, x, y};
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  unique_ptr<TrieNode> root(new TrieNode());
  insert(root.get(), a[1], 1, k);
  vector<int> ans;
  int best = -1;
  for (int i = 2; i <= n; ++i) {
    auto [index, x, y] = find_most_match(root.get(), a[i], k);
    if (y > best) {
      best = y;
      ans = {index, i, x};
    }
    insert(root.get(), a[i], i, k);
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
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
