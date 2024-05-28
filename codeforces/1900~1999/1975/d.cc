#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int a = 0, b = 0;
  cin >> a >> b;

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  function<void(int,int,vector<int>&)> dfs = [&](int node, int p, vector<int>& d) {
    for (int next_node : adj[node]) if (next_node != p) {
      d[next_node] = d[node] + 1;
      dfs(next_node, node, d);
    }
  };

  vector<int> a_dist(n+1);
  dfs(a, -1, a_dist);
  vector<int> b_dist(n+1);
  dfs(b, -1, b_dist);

  auto find_meeting_point = [&]() -> int {
    vector<bool> visited(n+1);
    queue<int> q;
    q.push(b);
    visited[b] = true;
    int step = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();

        if (a_dist[node] <= step) {
          return node;
        }

        for (int next_node : adj[node]) {
          if (visited[next_node]) continue;
          visited[next_node] = true; 
          q.push(next_node);
        }
      }
      step++;
    }
    return 0;
  };

  int meet = find_meeting_point();

  vector<int> meet_dist(n+1);
  dfs(meet, -1, meet_dist);

  int farthest = *max_element(meet_dist.begin(), meet_dist.end());
  int ans = 2 * (n - 1) - farthest + b_dist[meet];
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
