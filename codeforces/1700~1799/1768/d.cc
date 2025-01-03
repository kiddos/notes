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
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  DisjointSet ds(n+1);
  for (int i = 1; i <= n; ++i) {
    ds.join(p[i], i);
  }

  unordered_map<int,vector<int>> cycles;
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    cycles[p].push_back(i);
  }

  int ans = numeric_limits<int>::max();
  int num_cycles = cycles.size();
  // cout << "num_cycles=" << num_cycles << endl;
  for (int i = 2; i <= n; ++i) {
    int i1 = i-1, i2 = i;
    if (ds.find(i1) == ds.find(i2)) {
      ans = min(ans, n - (num_cycles + 1));
    } else {
      ans = min(ans, n - (num_cycles - 1));
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
