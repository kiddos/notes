#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
  TrieNode* children[11];
  bool end;

  TrieNode() : children{nullptr}, end(false) {}
  ~TrieNode() {
    for (int i = 0; i < 11; ++i) delete children[i];
  }
};

void insert(TrieNode* root, vector<int>& index, int m) {
  TrieNode* it = root;
  // cout << "index: " << endl;
  for (int i = 1; i <= m; ++i) {
    int idx = index[i];
    // cout << idx << " ";
    if (!it->children[idx]) it->children[idx] = new TrieNode();
    it = it->children[idx];
  }
  // cout << endl;
  it->end = true;
}

int search(TrieNode* root, vector<int>& p) {
  int m = p.size();
  TrieNode* it = root;
  for (int i = 0; i < m; ++i) {
    if (!it->children[p[i]]) return i;
    it = it->children[p[i]];
  }
  return m;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> p(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> p[i][j];
    }
  }

  unique_ptr<TrieNode> root(new TrieNode());
  for (int i = 0; i < n; ++i) {
    vector<int> index(m+1);
    for (int j = 0; j < m; ++j) {
      index[p[i][j]] = j+1;
    }

    insert(root.get(), index, m);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    ans.push_back(search(root.get(), p[i]));
  }

  for (int a : ans) cout << a << " ";
  cout << endl;
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
