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
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    edges.emplace_back(a, b);
  }

  DisjointSet ds(n);
  int component_count = n;
  vector<int> component_size(n, 1);
  int largest_component = 1;
  vector<pair<int,int>> ans;
  for (auto [a, b] : edges) {
    int pa = ds.find(a);
    int pb = ds.find(b);
    if (ds.join(a, b)) {
      int p = ds.find(a);
      if (pa != p) {
        component_size[p] += component_size[pa];
      } else {
        component_size[p] += component_size[pb];
      }
      component_count--;
      largest_component = max(largest_component, component_size[p]);
    }
    ans.emplace_back(component_count, largest_component);
  }

  for (auto [c, l] : ans) {
    cout << c << " " << l << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
