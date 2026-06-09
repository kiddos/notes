#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0, s = 0;
  cin >> n >> m >> k >> s;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> dists(k+1, vector<int>(n+1, -1));
  for (int t = 1; t <= k; ++t) {
    queue<int> q;
    for (int node = 1; node <= n; ++node) {
      if (a[node] == t) {
        q.push(node);
        dists[t][node] = 0;
      }
    }

    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();
        for (int next_node : adj[node]) {
          if (dists[t][next_node] >= 0) {
            continue;
          }
          dists[t][next_node] = dists[t][node] + 1;
          q.push(next_node);
        }
      }
    }
  }

  vector<i64> ans(n+1);
  for (int node = 1; node <= n; ++node) {
    priority_queue<int, vector<int>, less<>> pq;
    i64 total = 0;
    for (int t = 1; t <= k; ++t) {
      int d = dists[t][node];
      pq.push(d);
      total += d;
      while ((int)pq.size() > s) {
        int largest = pq.top();
        pq.pop();
        total -= largest;
      }
    }
    ans[node] = total;
  }

  for (int node = 1; node <= n; ++node) {
    cout << ans[node] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
