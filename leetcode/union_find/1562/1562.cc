#include <bits/stdc++.h>

using namespace std;

// Find Latest Group of Size M
//
// the rank in disjoint set will be the number of 1's in the group
// so if the rank(i) == m, answer could be this step
//
// if the previous/next element has a rank, then join it
// before join, we need to check if the prev/next element has rank == m

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
    if (rank_[px] >= rank_[py]) {
      rank_[px] += rank_[py];
      parent_[py] = parent_[px];
    } else {
      rank_[py] += rank_[px];
      parent_[px] = py;
    }
    return true;
  }

  int& rank(int index) { return rank_[index]; }

 private:
  vector<int> parent_, rank_;
};

class Solution {
 public:
  int findLatestStep(vector<int>& arr, int m) {
    int n = arr.size();
    if (m == n) return n;
    DisjointSet ds(n);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      int index = arr[i] - 1;
      ds.rank(index) = 1;
      for (int j : {index - 1, index + 1}) {
        if (j < 0 || j >= n) continue;
        if (ds.rank(ds.Find(j)) == m) ans = i;
        if (ds.rank(j)) ds.Union(index, j);
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> arr = {3, 5, 1, 2, 4};
  int m = 1;
  int ans = Solution().findLatestStep(arr, m);
  assert(ans == 4);
  return 0;
}
