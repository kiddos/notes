#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  map<int, vector<int>> stations;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0, c = 0;
    cin >> u >> v >> c;
    stations[c].push_back(u);
    stations[c].push_back(v);
  }
  int b = 0, e = 0;
  cin >> b >> e;

  map<int, vector<int>> adj;
  int color = n+1;
  for (auto& item : stations) {
    vector<int>& s = item.second;
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
    for (int station : s) {
      adj[station].push_back(color);
      adj[color].push_back(station);
    }
    color++;
  }

  map<int, int> dist;
  dist[b] = 0;
  queue<int> q;
  q.push(b);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      for (int next_node : adj[node]) {
        if (dist.count(next_node)) continue;
        dist[next_node] = dist[node]+1;
        q.push(next_node);
      }
    }
  }

  cout << dist[e] / 2 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}