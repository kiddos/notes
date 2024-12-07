#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
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
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  DisjointSet ds(n * m);
  vector<vector<int>> delta = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      for (int b = 0; b < 4; ++b) {
        vector<int>& d = delta[b];
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
        int wall1 = grid[r][c] & (1<<b);
        int b2 = (b + 2) % 4;
        int wall2 = grid[r2][c2] & (1<<b2);
        if (wall1 || wall2) continue;

        ds.join(r * m + c, r2 * m + c2);
      }
    }
  }

  unordered_map<int, vector<int>> rooms;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      int p = ds.find(r * m + c);
      rooms[p].push_back(r * m + c);
    }
  }
  vector<int> room_sizes;
  for (auto& [rid, cells] : rooms) {
    room_sizes.push_back(cells.size());
  }
  sort(room_sizes.rbegin(), room_sizes.rend());
  for (int rs : room_sizes) {
    cout << rs << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
