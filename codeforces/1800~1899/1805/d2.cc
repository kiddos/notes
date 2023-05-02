#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> adj(n+1);

  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> time(n+1, -1);
  function<void(int,int,int)> dfs = [&](int node, int parent, int t) {
    if (time[node] >= 0) return;
    time[node] = t;

    for (int next_node : adj[node]) if (next_node != parent) {
      dfs(next_node, node, t+1);
    }
  };

  dfs(1, -1, 0);
  int a = max_element(time.begin(), time.end()) - time.begin();
  fill(time.begin(), time.end(), -1);
  dfs(a, -1, 0);
  vector<int> dist1 = time;

  int b = max_element(time.begin(), time.end()) - time.begin();
  fill(time.begin(), time.end(), -1);
  dfs(b, -1, 0);
  vector<int> dist2 = time;

  vector<int> combine_dist(n+1);
  for (int node = 1; node <= n; ++node) {
    combine_dist[node] = max(dist1[node], dist2[node]);
  }

  // for (int node = 1; node <= n; ++node) cout << dist1[node] << " ";
  // cout << endl;

  // for (int node = 1; node <= n; ++node) cout << dist2[node] << " ";
  // cout << endl;

  // for (int node = 1; node <= n; ++node) cout << combine_dist[node] << " ";
  // cout << endl;

  sort(combine_dist.begin(), combine_dist.end());
  int ans = 1;
  for (int k = 0, j = 1; k < n; ++k) {
    while (j < combine_dist.size() && combine_dist[j] <= k) {
      ans++;
      ans = min(ans, n);
      j++;
    }
    cout << ans << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
