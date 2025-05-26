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
  int n = 0, p = 0;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<array<int,3>> edges;

  int i = 0;
  while (i < n) {
    int j = i;
    while (j+1 < n && a[j+1] % a[i] == 0) {
      j++;
    }
    for (int k = i+1; k <= j; ++k) {
      edges.push_back({a[i], i, k});
    }
    i = j+1;
  }
  i = n-1;
  while (i >= 0) {
    int j = i;
    while (j-1 >= 0 && a[j-1] % a[i] == 0) {
      j--;
    }
    for (int k = i; k >= j; --k) {
      edges.push_back({a[i], i, k});
    }
    i = j-1;
  }


  for (int j = 1; j < n; ++j) {
    edges.push_back({p, j-1, j});
  }
  sort(edges.begin(), edges.end());

  i64 ans = 0;
  DisjointSet ds(n);
  for (auto [w, i, j] : edges) {
    if (ds.join(i, j)) {
      ans += w;
    }
  }
  cout << ans << endl;
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
