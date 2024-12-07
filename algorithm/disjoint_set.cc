#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (x != parent_[x]) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
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
  ds.join(0, 1);
  ds.join(1, 3);
  ds.join(2, 5);
  ds.join(2, 6);

  unordered_map<int, vector<int>> groups;
  for (int i = 0; i < 10; ++i) {
    groups[ds.find(i)].push_back(i);
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
