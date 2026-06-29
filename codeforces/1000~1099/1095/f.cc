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

  bool join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return false;
    }
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

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<array<i64,3>> edges;
  for (int i = 0; i < m; ++i) {
    int x = 0, y = 0;
    i64 w = 0;
    cin >> x >> y >> w;
    x--;
    y--;
    edges.push_back({w, x, y});
  }

  vector<pair<i64,int>> nodes;
  for (int i = 0; i < n; ++i) {
    nodes.push_back({a[i], i});
  }
  sort(nodes.begin(), nodes.end());
  for (int i = 1; i < n; ++i) {
    i64 connect = nodes[0].first + nodes[i].first;
    edges.push_back({connect, nodes[0].second, nodes[i].second});
  }

  sort(edges.begin(), edges.end());

  DisjointSet ds(n);

  int size = edges.size();
  i64 ans = 0;
  int added = 0;
  for (int i = 0; i < size && added < n-1; ++i) {
    int node1 = edges[i][1];
    int node2 = edges[i][2];
    if (ds.join(node1, node2)) {
      // cout << "join " << node1 << "-" << node2 << " cost=" << edges[i][0] << endl;
      ans += edges[i][0];
      added++;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
