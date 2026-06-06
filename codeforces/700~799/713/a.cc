#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[2];
  int count;

  TrieNode() : children{nullptr}, count(0) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) {
      delete children[i];
    }
  }
};

constexpr int DIGIT_SIZE = 18;

vector<int> get_digits(i64 x) {
  if (x == 0) {
    return vector<int>(DIGIT_SIZE);
  }
  vector<int> ans;
  while (x > 0) {
    int d = x % 10;
    x /= 10;
    ans.push_back(d);
  }
  while ((int)ans.size() < DIGIT_SIZE) {
    ans.push_back(0);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void insert(TrieNode* root, i64 x) {
  vector<int> digits = get_digits(x);
  TrieNode* it = root;
  for (int i = 0; i < DIGIT_SIZE; ++i) {
    int d = digits[i];
    int p = d % 2;
    if (!it->children[p]) {
      it->children[p] = new TrieNode();
    }
    it = it->children[p];
  }
  it->count++;
}

void remove(TrieNode* root, i64 x) {
  vector<int> digits = get_digits(x);
  TrieNode* it = root;
  for (int i = 0; i < DIGIT_SIZE; ++i) {
    int d = digits[i];
    int p = d % 2;
    it = it->children[p];
  }
  it->count--;
}

int query(TrieNode* root, string suffix) {
  if ((int)suffix.length() < DIGIT_SIZE) {
    suffix = string(DIGIT_SIZE - suffix.length(), '0') + suffix;
  }
  TrieNode* it = root;
  for (int i = 0; i < DIGIT_SIZE; ++i) {
    int p = suffix[i] - '0';
    if (!it->children[p]) {
      return 0;
    }
    it = it->children[p];
  }
  return it->count;
}

void solve() {
  int n = 0;
  cin >> n;

  unique_ptr<TrieNode> root(new TrieNode());
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    char op = '\0';
    cin >> op ;
    if (op == '+') {
      i64 a = 0;
      cin >> a;
      insert(root.get(), a);
    } else if (op == '-') {
      i64 a = 0;
      cin >> a;
      remove(root.get(), a);
    } else if (op == '?') {
      string s;
      cin >> s;
      int result = query(root.get(), s);
      ans.push_back(result);
    }
  }
  for (int result : ans) {
    cout << result << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
