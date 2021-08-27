#include <bits/stdc++.h>

using namespace std;

vector<int> binary_lifting(vector<int>& parent, vector<vector<int>>& queries) {
  int n = parent.size();
  int l = ceil(log2(n));
  vector<vector<int>> parents(l, vector<int>(n));
  parents[0] = parent;
  for (int j = 1; j < l; ++j) {
    for (int i = 0; i < n; ++i) {
      int p = parents[j-1][i];
      parents[j][i] = p == -1 ? -1 : parents[j-1][p];
    }
  }

  vector<int> ans;
  for (vector<int>& q : queries) {
    int node = q[0], k = q[1];
    for (int j = 0; j < l; ++j) {
      if (k & (1<<j)) {
        node = parents[j][node];
        if (node == -1) break;
      }
    }
    ans.push_back(node);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
  vector<vector<int>> queries = {{3,1}, {5,2}, {6,3}};
  vector<int> ans = binary_lifting(parent, queries);
  for (int p : ans) cout << p << " ";
  cout << endl;

  // code here...
  return 0;
}
