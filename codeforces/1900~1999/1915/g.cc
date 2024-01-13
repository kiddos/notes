#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  vector<i64> s(n+1);
  for (int i = 1; i <= n; ++i)  cin >> s[i];

  for (int c = 1; c <= n; ++c) {
    vector<pair<int,int>>& list = adj[c];
    sort(list.begin(), list.end());
    vector<pair<int,int>> new_list;
    for (int i = 0; i < (int)list.size(); ++i) {
      if (new_list.empty() || new_list.back().first != list[i].first) {
        new_list.push_back(list[i]);
      }
    }
    adj[c] = std::move(new_list);
  }

  vector<map<int,i64>> dist(n+1);
  priority_queue<array<i64, 3>, vector<array<i64,3>>, greater<>> pq;
  pq.push({0, s[1], 1});
  dist[1][s[1]] = 0;

  while (!pq.empty()) {
    auto [time, bike, city] = pq.top();
    pq.pop();

    if (city == n) {
      cout << time << endl;
      return;
    }

    for (auto& [next_city, w] : adj[city]) {
      i64 new_dist = time + (i64) w * bike;
      int new_bike = min(bike, s[next_city]);
      if (!dist[next_city].count(bike) || new_dist < dist[next_city][bike]) {
        pq.push({new_dist, new_bike, next_city});
        dist[next_city][bike] = new_dist;
      }
    }
  }
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
