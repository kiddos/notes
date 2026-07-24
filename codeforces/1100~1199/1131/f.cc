#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), elements_(n) {
    iota(parent_.begin(), parent_.end(), 0);
    for (int i = 0; i < n; ++i) {
      elements_[i].push_back(i);
    }
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return;
    }

    if (elements_[px].size() >= elements_[py].size()) {
      parent_[py] = px;
      merge(elements_[px], elements_[py]);
    } else {
      parent_[px] = py;
      merge(elements_[py], elements_[px]);
    }
  }

  vector<int>& get_elements(int x) {
    int px = find(x);
    return elements_[px];
  }

  void merge(vector<int>& a, vector<int>& b) {
    for (int element : b) {
      a.push_back(element);
    }
  }

 private:
  vector<int> parent_;
  vector<vector<int>> elements_;
};


void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    edges.emplace_back(x, y);
  }

  DisjointSet ds(n+1);

  int size = edges.size();
  for (int i = 0; i < size; ++i) {
    auto [x, y] = edges[i];
    ds.join(x, y);
  }

  int p = ds.find(1);
  vector<int>& e = ds.get_elements(p);
  for (int index : e) {
    cout << index << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
