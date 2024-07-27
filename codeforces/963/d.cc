#include <bits/stdc++.h>

using namespace std;

constexpr int K = 26;

struct TrieNode {
  TrieNode* children[K];
  TrieNode* failure;
  unordered_set<int> indices;

  TrieNode() : children{nullptr}, failure(nullptr) {}
  ~TrieNode() {
    for (int i = 0; i < K; ++i)
      if (children[i] != this) delete children[i];
  }
};

void add_string(TrieNode* root, const string& s, int idx) {
  TrieNode* it = root;
  for (char ch : s) {
    int c = ch - 'a';
    if (!it->children[c]) it->children[c] = new TrieNode();
    it = it->children[c];
  }
  it->indices.insert(idx);
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
        if (node->children[i] != f) {
          for (int idx : f->indices) {
            node->children[i]->indices.insert(idx);
          }
        }
        q.push(node->children[i]);
      }
    }
  }
}

vector<int> solve(string s, vector<int>& k, vector<string>& m) {
  unique_ptr<TrieNode> root(new TrieNode());
  int n = m.size();
  for (int i = 0; i < n; ++i) {
    add_string(root.get(), m[i], i);
  }

  aho_corasick(root.get());

  TrieNode* node = root.get();
  int len = s.length();
  vector<vector<int>> indices(n);
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    while (!node->children[c]) {
      node = node->failure;
    }
    node = node->children[c];
    for (int idx : node->indices) {
      indices[idx].push_back(i);
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if ((int) indices[i].size() < k[i]) {
      ans[i] = -1;
    } else {
      int best = numeric_limits<int>::max();
      for (int j = 0; j <= (int) indices[i].size() - k[i]; ++j) {
        int len = indices[i][j + k[i] - 1] - indices[i][j] + m[i].length();
        best = min(best, len);
      }
      ans[i] = best;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = 0;
  cin >> n;
  vector<int> k(n);
  vector<string> m(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i] >> m[i];
  }

  vector<int> ans = solve(s, k, m);
  for (int a : ans) cout << a << '\n';
  cout << flush;
  return 0;
}
