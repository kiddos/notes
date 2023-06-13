#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
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

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  n *= 2;

  DisjointSet ds(n);

  vector<int> index;
  vector<pair<int,int>> levels;
  int level = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      index.push_back(i);
      level++;
    } else {
      // cout << "join " << index.back() << " " << i << endl;
      int i2 = index.back();
      ds.join(index.back(), i);
      index.pop_back();
      level--;

      while (!levels.empty() && levels.back().second > level) {
        // cout << "pop level: " << levels.back().first << endl;
        levels.pop_back();
      }
      while (!levels.empty() && levels.back().second == level) {
        // cout << "join level " << levels.back().first << " " << i << endl;
        ds.join(levels.back().first, i);
        levels.pop_back();
      }

      levels.push_back({i2, level});
    }
  }

  unordered_set<int> parents;
  for (int i = 0; i < n; ++i) {
    int p = ds.find(i);
    parents.insert(p);
  }

  cout << parents.size() << endl;
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
