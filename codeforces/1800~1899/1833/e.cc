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
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<unordered_set<int>> adj(n+1);
  DisjointSet ds(n+1);
  for (int i = 1; i <= n; ++i) {
    adj[i].insert(a[i]);
    adj[a[i]].insert(i);
    ds.join(i, a[i]);
  }

  unordered_map<int, vector<int>> group;
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    group[p].push_back(i);
  }

  int group_size = group.size();
  int ans_max = group_size;

  int complete = 0;
  for (auto& [parent, g] : group) {
    bool c = true;
    for (int member : g) {
      if (adj[member].size() < 2) {
        c = false;
        break;
      }
    }
    if (c) {
      complete++;
    }
  }

  int ans_min = complete + min(group_size - complete, 1);
  cout << ans_min << " " << ans_max << endl;
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
