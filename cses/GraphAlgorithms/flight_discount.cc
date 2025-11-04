#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  vector<vector<pair<int,int>>> adj(n+1);
  for (auto [a, b, c] : edges) {
    adj[a].push_back({b, c});
  }

  constexpr i64 inf = 1e18;
  vector<array<i64,2>> dists(n+1, {inf, inf});
  dists[1][0] = 0;

  set<array<i64,3>> s;
  s.insert({0, 1, 0});
  while (!s.empty()) {
    auto [d0, node, discounted] = *s.begin();
    s.erase(s.begin());
    for (auto [next_node, w] : adj[node]) {
      i64 d1 = d0 + w;
      if (d1 < dists[next_node][discounted]) {
        s.erase({dists[next_node][discounted], next_node, discounted});
        dists[next_node][discounted] = d1;
        s.insert({d1, next_node, discounted});
      }

      if (!discounted) {
        i64 d2 = d0 + w / 2;
        if (d2 < dists[next_node][1]) {
          s.erase({dists[next_node][discounted], next_node, 1});
          dists[next_node][1] = d2;
          s.insert({d2, next_node, 1});
        }
      }
    }
  }

  i64 ans = min(dists[n][0], dists[n][1]);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
