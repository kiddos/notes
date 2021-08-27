#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  int Find(int x) {
    if (x != parent_[x]) {
      parent_[x] = Find(parent_[x]);
    }
    return parent_[x];
  }

  void Union(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
  }

 private:
  vector<int> parent_, rank_;
};


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  DisjointSet ds(10);
  ds.Union(0, 1);
  ds.Union(1, 3);
  ds.Union(2, 5);
  ds.Union(2, 6);

  unordered_map<int, vector<int>> groups;
  for (int i = 0; i < 10; ++i) {
    groups[ds.Find(i)].push_back(i);
  }
  for (auto g : groups) {
    cout << "group " << g.first << " has : ";
    for (int item : g.second) {
      cout << item << " ";
    }
    cout << endl;
  }
  return 0;
}
