#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  ll c = 0;
  cin >> n >> k >> c;

  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dist(n);
  function<void(int,int,int)> compute_dist = [&](int node, int parent, int d) {
    dist[node] = d;
    for (int next_node : adj[node]) if (next_node != parent) {
      compute_dist(next_node, node, d+1);
    }
  };
  compute_dist(0, -1, 0);

  vector<int> dist0 = dist;
  int leaf1 = max_element(dist0.begin(), dist0.end()) - dist0.begin();

  fill(dist.begin(), dist.end(), 0);
  compute_dist(leaf1, -1, 0);

  vector<int> dist1 = dist;
  int leaf2 = max_element(dist1.begin(), dist1.end()) - dist1.begin();

  fill(dist.begin(), dist.end(), 0);
  compute_dist(leaf2, -1, 0);

  vector<int> dist2 = dist;

  ll ans = 0;
  function<void(int,int)> dfs = [&](int node, int parent) {
    ll max_length = max(dist1[node], dist2[node]);
    ll cost = max_length * k - dist0[node] * c;
    ans = max(ans, cost);
    for (int next_node : adj[node]) if (next_node != parent) {
      dfs(next_node, node);
    }
  };

  dfs(0, -1);
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
