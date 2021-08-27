#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int Find(int x) {
    if (parent_[x] != x) {
      parent_[x] = Find(parent_[x]);
    }
    return parent_[x];
  }

  bool Union(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return false;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
    return true;
  }

 private:
  vector<int> parent_, rank_;
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DisjointSet ds(n);
    for (vector<int>& edge : edges) {
      int u = edge[0] - 1, v = edge[1] - 1;
      if (!ds.Union(u, v)) return edge;
    }
    return {};
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  vector<int> ans = Solution().findRedundantConnection(edges);
  assert(ans[0] == 2);
  assert(ans[1] == 3);

  edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  ans = Solution().findRedundantConnection(edges);
  assert(ans[0] == 1);
  assert(ans[1] == 4);
  return 0;
}
