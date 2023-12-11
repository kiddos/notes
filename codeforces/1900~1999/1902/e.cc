#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[26];
  int count;

  TrieNode() : children{nullptr}, count(0) {}
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) delete children[i];
  }
};

void insert(TrieNode* root, const string& s) {
  int n = s.length();
  TrieNode* it = root;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (!it->children[c]) it->children[c] = new TrieNode();
    it = it->children[c];
    it->count++;
  }
}

i64 find_prefix(TrieNode* root, const string& s) {
  int n = s.length();
  TrieNode* it = root;
  i64 ans = 0;
  for (int i = n-1; i >= 0; --i) {
    int c = s[i] - 'a';
    if (!it->children[c]) {
      break;
    }
    it = it->children[c];
    ans += it->count;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;

  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  unique_ptr<TrieNode> root(new TrieNode());
  i64 total = 0;
  for (int i = 0; i < n; ++i) {
    insert(root.get(), s[i]);
    total += s[i].length();
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 len = s[i].length();
    ans += len * n + total - find_prefix(root.get(), s[i]) * 2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
