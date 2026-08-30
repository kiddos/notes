#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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

void solve() {
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  DisjointSet ds(n);
  for (int i = 0; i < x; ++i) {
    for (int j = i+x; j < n; j += x) {
      ds.join(i, j);
    }
  }
  for (int i = 0; i < y; ++i) {
    for (int j = i+y; j < n; j += y) {
      ds.join(i, j);
    }
  }

  vector<vector<int>> values(n);
  for (int i = 0; i < n; ++i) {
    int parent = ds.find(i);
    values[parent].push_back(p[i]);
  }

  for (int i = 0; i < n; ++i) {
    sort(values[i].begin(), values[i].end());
  }

  for (int i = n-1; i >= 0; --i) {
    int parent = ds.find(i);
    p[i] = values[parent].back();
    values[parent].pop_back();
  }

  for (int i = 1; i < n; ++i) {
    if (p[i-1] > p[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
