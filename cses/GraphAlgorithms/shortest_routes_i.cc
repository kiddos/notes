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

  vector<vector<array<int,2>>> adj(n+1);
  for (auto [a, b, c] : edges) {
    adj[a].push_back({b, c});
  }

  const i64 inf = 1e18;
  vector<i64> dists(n+1, inf);
  dists[1] = 0;
  set<pair<i64,int>> s;
  s.insert({0, 1});
  while (!s.empty()) {
    auto [d0, node] = *s.begin();
    s.erase(s.begin());

    for (auto [next_node, w] : adj[node]) {
      i64 d = d0 + w;
      if (d < dists[next_node]) {
        s.erase({dists[next_node], next_node});
        dists[next_node] = d;
        s.insert({d, next_node});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << dists[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
