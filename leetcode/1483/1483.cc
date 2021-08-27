#include <bits/stdc++.h>

using namespace std;

// Kth Ancestor of a Tree Node
//
// need to learn binary lifting
//
// preprocessing takes O(nlog(n))
// query takes O(log(n))

class TreeAncestor {
 public:
  TreeAncestor(int n, vector<int>& parent) {
    int l = ceil(log2(n));
    parent_ = vector<vector<int>>(n, vector<int>(l));
    for (int i = 0; i < n; ++i) {
      parent_[i][0] = parent[i];
    }
    for (int j = 1; j < l; ++j) {
      for (int i = 0; i < n; ++i) {
        int p = parent_[i][j - 1];
        if (p != -1) parent_[i][j] = parent_[p][j - 1];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    int l = parent_[0].size();
    for (int j = 0; j < l; ++j) {
      if (k & (1 << j)) {
        node = parent_[node][j];
      }
    }
    return node;
  }

 private:
  vector<vector<int>> parent_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
  vector<vector<int>> queries = {{3,1}, {5,2}, {6,3}};
  TreeAncestor tree(7, parent);
  for (auto q : queries) {
    int ans = tree.getKthAncestor(q[0], q[1]);
    cout << ans << " ";
  }
  cout << endl;

  // code here...
  return 0;
}
