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
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> d(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }

  DisjointSet ds(n+1);
  for (int i = 1; i <= n; ++i) {
    ds.join(i, p[i]);
  }

  vector<int> group_size(n+1);
  for (int i = 1; i <= n; ++i) {
    int parent = ds.find(p[i]);
    group_size[parent]++;
  }
  vector<int> current_size = group_size;

  int ops = n;
  vector<int> ans = {n};
  for (int i = n; i > 1; --i) {
    int parent = ds.find(p[d[i]]);
    current_size[parent]--;
    if (current_size[parent] == 0) {
      ops -= group_size[parent];
    }
    ans.push_back(ops);
  }
  reverse(ans.begin(), ans.end());
  for (int ops : ans) {
    cout << ops << " ";
  }
  cout << endl;
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
