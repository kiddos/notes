#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n) {
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

    parent_[px] = py;
  }

 private:
  vector<int> parent_;
};

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

  int get(int i) {
    if (i == 0) return 0;

    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

  void update(int i, int x) {
    if (i == 0) return;

    int n = data_.size();
    while (i < n) {
      data_[i] += x;
      i += (i & -i);
    }
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  s = " " + s;

  vector<int> index(n+1);
  DisjointSet ds(n+2);
  int k = 0;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;

    for (int i = ds.find(l); i <= r; i = ds.find(i)) {
      index[i] = ++k;
      ds.join(i, i+1);
      // cout << "i=" << i << endl;
    }
  }

  int total = 0;
  FenwickTree tree(n+1);
  for (int i = 1; i <= n; ++i) if (s[i] == '1') {
    tree.update(index[i], 1);
    total++;
  }

  for (int i = 0; i < q; ++i) {
    int x = 0;
    cin >> x;

    if (s[x] == '1') {
      tree.update(index[x], -1);
      total--;
      s[x] = '0';
    } else if (s[x] == '0') {
      tree.update(index[x], 1);
      total++;
      s[x] = '1';
    }

    int y = min(total, k);
    int ans = y - tree.get(y);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
