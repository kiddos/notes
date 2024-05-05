#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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
    if (px == py) {
      return;
    }
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
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  DisjointSet ds(n);
  for (int i = x; i < n; ++i) {
    ds.join(0, i);
    ds.join(i-x, i);
  }

  unordered_map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    int p = ds.find(i);
    indices[p].push_back(i);
  }
  for (auto& [_, idx] : indices) {
    vector<int> vals;
    for (int i : idx) vals.push_back(a[i]);
    sort(vals.begin(), vals.end());
    int size = idx.size();
    for (int i = 0; i < size; ++i) {
      a[idx[i]] = vals[i];
    }
  }

  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
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
