#include <bits/stdc++.h>

using namespace std;

// Couples Holding Hands
//
// DisjointSet
// initially row[i] and row[i+1] is joined
// only need to swap if i and i+1 is not in the same set

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int Find(int x) {
    if (x != parent_[x]) {
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
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i += 2) {
      ds.Union(row[i], row[i + 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i += 2) {
      int p1 = ds.Find(i), p2 = ds.Find(i + 1);
      if (p1 != p2) {
        ds.Union(i, i + 1);
        ans++;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> row = {0, 2, 1, 3};
  int ans = Solution().minSwapsCouples(row);
  assert(ans == 1);

  row = {3, 2, 0, 1};
  ans = Solution().minSwapsCouples(row);
  assert(ans == 0);
  return 0;
}
