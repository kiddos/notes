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
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }

  DisjointSet ds(n+1);
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }

  for (int i = 0; i < m; ++i) {
    ds.join(l[i], r[i]);
  }

  map<int, vector<int>> colors;
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    colors[p].push_back(c[i]);
  }

  int ans = 0;
  for (auto [p, color] : colors) {
    map<int,int> freq;
    int total = color.size();
    int most_count = 0;
    for (int col : color) {
      most_count = max(most_count, ++freq[col]);
    }
    int repaint = total - most_count;
    ans += repaint;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
