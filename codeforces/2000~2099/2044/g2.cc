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
  vector<int> r(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> r[i];
  }

  vector<int> last(n+1);
  vector<int> state(n+1);
  vector<bool> is_cycle(n+1);
  function<void(int)> mark_cycle = [&](int node) {
    if (state[node]) {
      if (state[node] == 1) {
        // found cycle
        int x = node;
        do {
          is_cycle[x] = true;
          x = last[x];
        } while (x != node);
      }
      return;
    }

    state[node] = 1;
    last[r[node]] = node;
    mark_cycle(r[node]);
    state[node] = 2;
  };

  for (int node = 1; node <= n; ++node) {
    if (!state[node]) {
      mark_cycle(node);
    }
  }

  DisjointSet ds(n+1);
  for (int node = 1; node <= n; ++node) {
    if (!is_cycle[node] && !is_cycle[r[node]]) {
      ds.join(node, r[node]);
    }
  }

  vector<vector<int>> branch(n+1);
  for (int node = 1; node <= n; ++node) {
    if (!is_cycle[node]) {
      int p = ds.find(node);
      branch[p].push_back(node);
    }
  }

  int ans = 2;
  for (int p = 1; p <= n; ++p) {
    ans = max(ans, (int)branch[p].size() + 2);
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
