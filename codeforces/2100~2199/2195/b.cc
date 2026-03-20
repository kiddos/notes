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
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  DisjointSet ds(n+1);
  for (int i = 1; i <= n; ++i) {
    int idx = i;
    while (idx <= n) {
      ds.join(i, idx);
      idx *= 2;
    }
  }
  vector<vector<int>> group(n+1);
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    group[p].push_back(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    sort(group[i].rbegin(), group[i].rend());
  }
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    b[i] = group[p].back();
    group[p].pop_back();
  }

  for (int i = 2; i <= n; ++i) {
    if (b[i-1] > b[i]) {
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
