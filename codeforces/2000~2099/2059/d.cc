#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
vector<vector<int>> create_adj(int n, vector<pair<int,int>>& edges) {
  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}
 
void solve() {
  int n = 0, s1 = 0, s2 = 0;
  cin >> n >> s1 >> s2;
  int m1 = 0;
  cin >> m1;
  vector<pair<int,int>> edges1;
  for (int i = 0; i < m1; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges1.emplace_back(min(a, b), max(a, b));
  }
  int m2 = 0;
  cin >> m2;
  vector<pair<int,int>> edges2;
  for (int i = 0; i < m2; ++i) {
    int c = 0, d = 0;
    cin >> c >> d;
    edges2.emplace_back(min(c, d), max(c, d));
  }
 
  set<int> endpoints;
  set<pair<int,int>> pairs(edges1.begin(), edges1.end());
  for (auto p : edges2) {
    if (pairs.count(p)) {
      endpoints.insert(p.first);
      endpoints.insert(p.second);
    }
  }
 
  vector<vector<int>> adj1 = create_adj(n, edges1);
  vector<vector<int>> adj2 = create_adj(n, edges2);
 
  constexpr i64 inf = 1e9;
  set<array<i64,3>> s;
  s.insert({0, s1, s2});
  vector<vector<i64>> dist(n+1, vector<i64>(n+1, inf));
  dist[s1][s2] = 0;
  while (!s.empty()) {
    auto [d, v1, v2] = *s.begin();
    s.erase(s.begin());
    for (int u1 : adj1[v1]) {
      for (int u2 : adj2[v2]) {
        i64 cost = abs(u1 - u2);
        if (d + cost < dist[u1][u2]) {
          s.erase({dist[u1][u2], u1, u2});
          dist[u1][u2] = d + cost;
          s.insert({dist[u1][u2], u1, u2});
        }
      }
    }
  }

  i64 ans = inf;
  for (int node = 1; node <= n; ++node) {
    if (endpoints.count(node) && dist[node][node] < inf) {
      ans = min(ans, dist[node][node]);;
    }
  }
 
  if (ans >= inf) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
