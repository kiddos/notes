#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TrieNode {
  TrieNode* children[2];
  int index;

  TrieNode() : children{nullptr}, index(-1) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) {
      delete children[i];
    }
  }
};

void insert(TrieNode* root, vector<int>& row, int threshold, int index) {
  TrieNode* it = root;
  for (int x : row) {
    int b = x >= threshold ? 1 : 0;
    if (!it->children[b]) {
      it->children[b] = new TrieNode();
    }
    it = it->children[b];
  }
  if (it->index < 0) {
    it->index = index;
  }
}

int find(TrieNode* node, int i, int m, vector<int>& row, int threshold) {
  if (!node) {
    return -1;
  }
  if (i >= m) {
    return node->index;
  }

  int b = row[i] >= threshold ? 1 : 0;
  if (b == 0) {
    return find(node->children[1], i+1, m, row, threshold);
  } else {
    int result = find(node->children[0], i+1, m, row, threshold);
    if (result >= 0) {
      return result;
    }
    result = find(node->children[1], i+1, m, row, threshold);
    return result;
  }
}

bool possible(vector<vector<int>>& a, int threshold, pair<int,int>& ans) {
  int n = a.size(), m = a[0].size();
  unique_ptr<TrieNode> root(new TrieNode());
  for (int i = 0; i < n; ++i) {
    insert(root.get(), a[i], threshold, i);

    int result = find(root.get(), 0, m, a[i], threshold);
    if (result >= 0) {
      ans.first = result;
      ans.second = i;
      return true;
    }
  }
  return false;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int max_val = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      max_val = max(max_val, a[i][j]);
    }
  }

  int l = 0, r = max_val;
  pair<int,int> ans;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(a, mid, ans)) {
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  cout << ans.first+1 << " " << ans.second+1  << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
