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

  vector<string> g(n), w(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i] >> w[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (g[i] == g[j]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
      if (w[i] == w[j]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int m = 1<<n;
  int max_playlist_size = 0;
  vector<vector<int>> dp(m, vector<int>(n, -1));
  for (int s = 0; s < n; ++s) {
    int mask = 1<<s;
    dp[mask][s] = 1;
    max_playlist_size = max(max_playlist_size, 1);
  }

  for (int mask = 0; mask < m; ++mask) {
    for (int s1 = 0; s1 < n; ++s1) {
      if (dp[mask][s1] < 0) continue;

      if (mask & (1 << s1)) {
        for (int next_song : adj[s1]) {
          if (!(mask & (1<<next_song))) {
            int mask2 = mask | (1<<next_song);
            dp[mask2][next_song] = max(dp[mask2][next_song], dp[mask][s1] + 1);
            max_playlist_size = max(max_playlist_size, dp[mask2][next_song]);
          }
        }
      }
    }
  }

  int ans = n - max_playlist_size;
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
