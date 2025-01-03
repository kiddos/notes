#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[26];
  int count;
  TrieNode() : children{nullptr}, count(0) {}
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      delete children[i];
    }
  }
};

void insert_suffix(TrieNode* root, const string& s) {
  string r(s.rbegin(), s.rend());
  TrieNode* it = root;
  for (char ch : r) {
    int c = ch - 'a';
    if (!it->children[c]) it->children[c] = new TrieNode();
    it = it->children[c];
    it->count++;
  }
}

int find(TrieNode* root, const string& s) {
  TrieNode* it = root;
  for (char ch : s) {
    int c = ch - 'a';
    if (!it->children[c]) return 0;
    it = it->children[c];
  }
  return it->count;
}

bool is_palindrome(const string& s) {
  int l = 0, r = s.length()-1;
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  unique_ptr<TrieNode> len2(new TrieNode());
  unique_ptr<TrieNode> len3(new TrieNode());
  for (int i = n-1; i >= 0; --i) {
    int len = s[i].length();
    if (is_palindrome(s[i])) {
      cout << "YES" << endl;
      return;
    }

    if (len == 1) {
      cout << "YES" << endl;
      return;
    } else if (len == 2) {
      int r1 = find(len2.get(), s[i]);
      int r2 = find(len3.get(), s[i]);
      if (r1 || r2) {
        cout << "YES" << endl;
        return;
      }

      insert_suffix(len2.get(), s[i]);
    } else if (len == 3) {
      int r1 = find(len2.get(), s[i].substr(0, 2));
      int r2 = find(len3.get(), s[i]);
      if (r1 || r2) {
        cout << "YES" << endl;
        return;
      }
      insert_suffix(len3.get(), s[i]);
    }
  }
  cout << "NO" << endl;
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
