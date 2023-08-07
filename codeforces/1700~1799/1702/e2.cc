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

  DisjointSet ds(n+1);
  bool has_same = false;
  vector<int> counts(n+1);
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;

    ds.join(a, b);
    counts[a]++;
    counts[b]++;

    if (a == b) {
      has_same = true;
    }
  }

  if (has_same) {
    cout << "NO" << endl;
    return;
  }

  vector<int> group_size(n+1);
  for (int x = 1; x <= n; ++x) {
    if (counts[x] != 2) {
      cout << "NO" << endl;
      return;
    }
    int p = ds.find(x);
    group_size[p]++;
  }

  for (int p = 1; p <= n; ++p) if (group_size[p]) {
    if (group_size[p] % 2 != 0) {
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
