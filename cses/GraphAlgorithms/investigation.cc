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

  constexpr i64 inf = 1e18;
  set<pair<i64,int>> s;
  s.insert({0, 1});

  vector<i64> count(n+1);
  vector<i64> min_flight(n+1, inf);
  vector<i64> max_flight(n+1);
  vector<i64> dists(n+1, inf);
  dists[1] = 0;
  count[1] = 1;
  min_flight[1] = 0;

  constexpr int MOD = 1e9 + 7;

  while (!s.empty()) {
    auto [d0, node] = *s.begin();
    s.erase(s.begin());
    for (auto [next_node, w] : adj[node]) {
      i64 d1 = d0 + w;
      if (d1 < dists[next_node]) {
        s.erase({dists[next_node], next_node});
        dists[next_node] = d1;
        s.insert({d1, next_node});
        count[next_node] = count[node];
        min_flight[next_node] = min_flight[node] + 1;
        max_flight[next_node] = max_flight[node] + 1;
      } else if (d1 == dists[next_node]) {
        count[next_node] += count[node];
        count[next_node] %= MOD;
        min_flight[next_node] = min(min_flight[next_node], min_flight[node] + 1);
        max_flight[next_node] = max(max_flight[next_node], max_flight[node] + 1);
      }
    }
  }

  vector<i64> ans(4);
  ans[0] = dists[n];
  ans[1] = count[n];
  ans[2] = min_flight[n];
  ans[3] = max_flight[n];

  for (int i = 0; i < 4; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
